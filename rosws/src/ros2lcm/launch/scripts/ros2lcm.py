#!/usr/bin/python3
from logging.config import listen
import lcm
import select
import mars_message
from mars_message.PointCloud import PointCloud

import rospy
import geometry_msgs.msg
import sensor_msgs.msg
import std_msgs.msg
import genpy
import math
import nav_msgs.msg
import tf2_ros
import tf_conversions
from tf import transformations as t
import tf

import sys
import signal

lc = lcm.LCM()

global global_bumperVor
global_bumperVor = 0x00
global global_Bmptime
global_Bmptime = std_msgs.msg.Time


class RosMapping(object):
     def __init__(self, topic, lcm_type, ros_type, frame, to_lcm, lcm_channel):
        self.topic = topic
        self.lcm_type = lcm_type
        self.ros_type = ros_type
        self.frame = frame
        self.to_lcm = to_lcm
        self.lcm_channel = lcm_channel

def mapping_stamp(stamp):
    timestamp = int(stamp.to_sec()*1000)
    return timestamp

def mapping_point(point : geometry_msgs.msg.Point):
    msg = mars_message.Vector3()
    msg.x = point.x
    msg.y = point.y
    msg.z = point.z
    return msg

def mapping_quaternion(quat: geometry_msgs.msg.Quaternion):
    msg = mars_message.Quaternion()
    msg.w = quat.w
    msg.x = quat.x
    msg.y = quat.y
    msg.z = quat.z
    return msg

def mapping_poseP(pose : geometry_msgs.msg.PoseStamped, ros : RosMapping):
    msg = mars_message.Pose()
    msg.pose = mapping_point(pose.pose.position)
    msg.orientation = mapping_quaternion(pose.pose.orientation)
    lc.publish(ros.lcm_channel, msg.encode())

def mapping_pose(pose : geometry_msgs.msg.PoseWithCovariance):
    msg = mars_message.Pose()
    msg.pose = mapping_point(pose.pose.position)
    msg.orientation = mapping_quaternion(pose.pose.orientation)
    return msg

def mapping_vector3(vector : geometry_msgs.msg.Vector3):
    msg = mars_message.Vector3()
    msg.x = vector.x
    msg.y = vector.y
    msg.z = vector.z
    return msg

def mapping_twsit(twist : geometry_msgs.msg.Twist):
    msg = mars_message.Twist()
    msg.angularVelocity = mapping_vector3(twist.angular)
    msg.linearVelocity = mapping_vector3(twist.linear)
    return msg

def mapping_imu(imu : sensor_msgs.msg.Imu, ros : RosMapping):
    msg = mars_message.Imu()
    msg.angularVelocity = mapping_vector3(imu.angular_velocity)
    msg.linearAcceleraion = mapping_vector3(imu.linear_acceleration)
    msg.angularVelocityCovariance = imu.angular_velocity_covariance
    msg.linearAcceleraionCovariance = imu.linear_acceleration_covariance
    msg.orientation = mapping_quaternion(imu.orientation)
    msg.orientationCovariance = imu.orientation_covariance
    lc.publish(ros.lcm_channel, msg.encode())

# odom -> coder
def mapping_odom(odom : nav_msgs.msg.Odometry, ros : RosMapping):
    msg = mars_message.Odometry()
    msg.timestampMs = mapping_stamp(odom.header.stamp)
    msg.pose = mapping_pose(odom.pose)
    msg.angularVelocity = mapping_vector3(odom.twist.twist.angular)
    msg.linearVelocity = mapping_vector3(odom.twist.twist.linear)
    lc.publish(ros.lcm_channel, msg.encode())

def mapping_laser(scan : sensor_msgs.msg.LaserScan, ros : RosMapping):
    msg = mars_message.LaserScan()
    msg.angleIncrement = scan.angle_increment
    msg.angleMax = scan.angle_max
    msg.angleMin = scan.angle_min
    msg.intensities = scan.intensities
    msg.rangeMax = scan.range_max
    msg.rangeMin = scan.range_min
    msg.ranges = scan.ranges
    msg.scanTime = scan.scan_time
    msg.timeIncrement = scan.time_increment
    msg.count = len(scan.ranges)
    msg.timestampMs = mapping_stamp(scan.header.stamp)
    lc.publish(ros.lcm_channel, msg.encode())

def mapping_pointCloud2D(scan : sensor_msgs.msg.LaserScan, ros : RosMapping):
    msg = mars_message.PointCloud2()
    msg.timestampMs = mapping_stamp(scan.header.stamp)
    msg.scanTime = scan.scan_time
    msg.count = len(scan.ranges)
    for r in scan.ranges: 
        msg.intensities.append(20)
    anglenow = scan.angle_min
    for r in scan.ranges:
        point = mars_message.Point()
        point.x = r*math.cos(anglenow)
        point.y = r*math.sin(anglenow)
        point.z = 0
        msg.points.append(point)
        anglenow=anglenow+scan.angle_increment
        if anglenow>scan.angle_max: anglenow=scan.angle_max
    lc.publish(ros.lcm_channel, msg.encode())



def mapping_bumper0(bumper : sensor_msgs.msg.Range, ros : RosMapping):
    msg = mars_message.Bumper()
    msg.timestampMs = mapping_stamp(bumper.header.stamp)
    msg.count = bumper.radiation_type 
    bmp = mars_message.Vector3()
    tfBuffer = tf2_ros.Buffer()
    listener = tf2_ros.TransformListener(tfBuffer)
    try:
        trans=tfBuffer.lookup_transform("odom", "base_link", rospy.Time.now())
        p = trans.transform.translation
        q = trans.transform.rotation
        print("work",trans.transform.translation.x,trans.transform.translation.y,trans.transform.translation.z)
        bmp.x = trans.transform.translation.x-bumper.field_of_view      #用于传输碰撞坐标的与名字无关
        bmp.y = trans.transform.translation.y-bumper.min_range
        bmp.z = trans.transform.translation.x-bumper.max_range
    except Exception as e:
        print(e)
    
    print("bmp",bmp.x,bmp.y,bmp.z)
    if bmp.x >0.01:
        if bmp.y >=0.06:
            msg.mask = 0x2
        else : 
            if bmp.y <= -0.06:
                msg.mask = 0x1
            else :
                msg.mask = 0x3

    print("msg.count:",msg.count,"msg.mask:",msg.mask)
    lc.publish(ros.lcm_channel, msg.encode())
    

def mapping_bumper(bumper : sensor_msgs.msg.Range, ros : RosMapping):
    msg = mars_message.Bumper()
    msg.timestampMs = mapping_stamp(bumper.header.stamp)
    global global_bumperVor
    global global_Bmptime
    try:
        #print("bumper:",global_bumperVor,global_Bmptime,(rospy.Time.now().to_nsec()/1000000))
        if bumper.radiation_type:
            msg.count = bumper.radiation_type 
            if global_bumperVor:
                if msg.timestampMs < (global_Bmptime+500):
                    # print("bumper")
                    msg.mask = global_bumperVor
                    lc.publish(ros.lcm_channel, msg.encode())
            else :
                # print("other bumper")
                pass
        else :
            msg.count = 0x4 
            msg.mask = 0
            if global_Bmptime < ((rospy.Time.now().to_nsec()/1000000)-300):
                global_bumperVor = 0
                #print("No bumper")
            lc.publish(ros.lcm_channel, msg.encode())
    except Exception as e:
        print(e)
        global_Bmptime = msg.timestampMs


def mapping_edge(edge : sensor_msgs.msg.Range, ros : RosMapping):
    msg = mars_message.Range()
    msg.rangeMM = int(edge.range*1000)
    lc.publish(ros.lcm_channel, msg.encode())


def mapping_bumper1(edge : sensor_msgs.msg.Range, ros : RosMapping):
    msg = mars_message.Bumper()
    msg.timestampMs = mapping_stamp(edge.header.stamp)
    msg.count = 4
    global global_bumperVor
    global global_Bmptime
    if edge.range<0.085:
        msg.mask = 0x1
        global_bumperVor = msg.mask
        global_Bmptime = msg.timestampMs
        #print("bumper---01")
    else :
        msg.mask = 0x0

def mapping_bumper2(edge : sensor_msgs.msg.Range, ros : RosMapping):
    msg = mars_message.Bumper()
    msg.timestampMs = mapping_stamp(edge.header.stamp)
    msg.count = 4
    global global_bumperVor
    global global_Bmptime
    if edge.range<0.085:
        msg.mask = 0x2
        global_bumperVor = msg.mask
        global_Bmptime = msg.timestampMs
        #print("bumper---02")
    else :
        msg.mask = 0x0

def mapping_bumper3(edge : sensor_msgs.msg.Range, ros : RosMapping):
    msg = mars_message.Bumper()
    msg.timestampMs = mapping_stamp(edge.header.stamp)
    msg.count = 4
    global global_bumperVor
    global global_Bmptime
    if edge.range<0.085: 
        msg.mask = 0x3
        global_bumperVor = msg.mask
        global_Bmptime = msg.timestampMs
        #print("bumper---03")
    else :
        msg.mask = 0x0


ros_mappings = [
    RosMapping("/goal", mars_message.Pose, geometry_msgs.msg.PoseStamped, "odom", mapping_poseP, "/goal"),
    RosMapping("/scan", mars_message.LaserScan, sensor_msgs.msg.LaserScan, "base_link", mapping_laser, "vscan"),
    RosMapping("/scan", mars_message.PointCloud2, sensor_msgs.msg.LaserScan, "base_link", mapping_pointCloud2D, "SCAN"),
    RosMapping("/sweeper_drive_controller/odom", mars_message.Odometry, nav_msgs.msg.Odometry, "base_link", mapping_odom, "REALODOM"),
    RosMapping("/lcmbumper", mars_message.Bumper, sensor_msgs.msg.Range, "base_link", mapping_bumper, "Mbump"),    #暂时用 tof 替代前档碰撞因坐标无法正常读取，用 tof 判断方向，用碰撞判断有效性
    RosMapping("/ir/right_front", mars_message.Bumper, sensor_msgs.msg.Range, "base_link", mapping_bumper1, "Mbump"),
    RosMapping("/ir/left_front", mars_message.Bumper, sensor_msgs.msg.Range, "base_link", mapping_bumper2, "Mbump"),
    RosMapping("/ir/front", mars_message.Bumper, sensor_msgs.msg.Range, "base_link", mapping_bumper3, "Mbump"),
    RosMapping("/ir/right", mars_message.Range, sensor_msgs.msg.Range, "base_link", mapping_edge, "Medge"),
    RosMapping("/imu", mars_message.Imu, sensor_msgs.msg.Imu, "base_link", mapping_imu, "vimu"),
    RosMapping("/imu", mars_message.Imu, sensor_msgs.msg.Imu, "base_link", mapping_imu, "IMU"),
]


def main():
    rospy.init_node("ros2lcm")
    for t in ros_mappings:
        rospy.Subscriber(t.topic, t.ros_type, t.to_lcm, t)
    rospy.spin()
if __name__ == "__main__":
    main()