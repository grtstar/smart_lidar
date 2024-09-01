#!/usr/bin/python3
from logging.config import listen
import lcm
import select
import mars_message
from mars_message.PointCloud import PointCloud

import rospy
import genpy
import std_msgs.msg
import geometry_msgs.msg
import nav_msgs.msg
import sensor_msgs.msg
import nav_msgs.msg
import visualization_msgs.msg
import tf2_ros
import tf_conversions
from tf import transformations as t
import tf

import sys
import signal

def signal_handler(signal, frame):
        sys.exit(0)

lcm_mappings = {}
lcm_pubs = {}

def mapping_stamp(stamp):
    timestamp = genpy.Time().from_sec(stamp/1000.0)
    return timestamp

def mapping_point(point : mars_message.Vector3):
    msg = geometry_msgs.msg.Point()
    msg.x = point.x
    msg.y = point.y
    msg.z = point.z
    return msg

def mapping_point(point : mars_message.Point):
    msg = geometry_msgs.msg.Point()
    msg.x = point.x
    msg.y = point.y
    msg.z = point.z
    return msg

def mapping_quaternion(quat: mars_message.Quaternion):
    msg = geometry_msgs.msg.Quaternion()
    msg.w = quat.w
    msg.x = quat.x
    msg.y = quat.y
    msg.z = quat.z
    return msg

def mapping_pose(pose : mars_message.Pose):
    msg = geometry_msgs.msg.Pose()
    msg.position = mapping_point(pose.pose)
    msg.orientation = mapping_quaternion(pose.orientation)
    return msg

def mapping_path(path : mars_message.Path, frame_id):
    msg = nav_msgs.msg.Path()
    for p in path.points:
        posestamp = geometry_msgs.msg.PoseStamped()
        posestamp.header.stamp = mapping_stamp(0)
        posestamp.header.frame_id = frame_id
        posestamp.pose.position = mapping_point(p)
        posestamp.pose.orientation.w = 1.0
        posestamp.pose.orientation.x = 0.0
        posestamp.pose.orientation.y = 0.0
        posestamp.pose.orientation.z = 0.0
        msg.poses.append(posestamp)

    msg.header.stamp = mapping_stamp(0)
    msg.header.frame_id = frame_id
    return msg

def mapping_scan(scan : mars_message.LaserScan, frame_id):
    msg = sensor_msgs.msg.LaserScan()
    msg.angle_increment = scan.angleIncrement
    msg.angle_max = scan.angleMax
    msg.angle_min = scan.angleMin
    msg.intensities = scan.intensities
    msg.range_max = scan.rangeMax
    msg.range_min = scan.rangeMin
    msg.ranges = scan.ranges
    msg.scan_time = scan.scanTime
    msg.time_increment = scan.timeIncrement

    msg.header.stamp = mapping_stamp(scan.timestampMs)
    msg.header.frame_id = frame_id
    return msg

def mapping_map(map : mars_message.GridMap, frame_id):
    msg = nav_msgs.msg.OccupancyGrid()
    msg.info.width = map.width
    msg.info.height = map.height
    msg.info.resolution = map.resolution
    msg.info.map_load_time = mapping_stamp(map.mapLoadTime)
    msg.info.origin = mapping_pose(map.origin)
    msg.data = map.data

    msg.header.stamp = mapping_stamp(map.timestampMs)
    msg.header.frame_id = frame_id
    return msg

def mapping_imu(imu : mars_message.Imu, frame_id):
    msg = sensor_msgs.msg.Imu()
    msg.angular_velocity = mapping_vector3(imu.angularVelocity)
    msg.linear_acceleration = mapping_vector3(imu.linearAcceleraion)
    msg.angular_velocity_covariance = imu.angularVelocityCovariance
    msg.linear_acceleration_covariance = imu.linearAcceleraionCovariance
    msg.orientation = mapping_quaternion(imu.orientation)
    msg.orientation_covariance = imu.orientationCovariance

    msg.header.stamp = rospy.Time.now() #mapping_stamp(imu.timestampMs)
    msg.header.frame_id = frame_id
    return msg


def mapping_twist(twist : mars_message.Twist):
    msg = geometry_msgs.msg.Twist()
    msg.angular = mapping_vector3(twist.angularVelocity)
    msg.linear = mapping_vector3(twist.linearVelocity)
    return msg

def mapping_speed(twist : mars_message.Twist, frame_id):
    msg = geometry_msgs.msg.Twist()
    msg.angular = mapping_vector3(twist.angularVelocity)
    msg.linear = mapping_vector3(twist.linearVelocity)
    return msg

def mapping_vector3(vector : mars_message.Vector3):
    msg = geometry_msgs.msg.Vector3()
    msg.x = vector.x
    msg.y = vector.y
    msg.z = vector.z
    return msg

def mapping_pointcloud(cloud : mars_message.PointCloud, frame_id):
    msg = sensor_msgs.msg.PointCloud()
    for i in range(len(cloud.points)):
        msg.points.append(geometry_msgs.msg.Point(cloud.points[i].x, cloud.points[i].y, cloud.points[i].z)) 

    channel = sensor_msgs.msg.ChannelFloat32()
    channel.name = "intensity"
    channel.values = cloud.intensities
    msg.channels.append(channel)   
    msg.header.stamp = mapping_stamp(cloud.timestampMs)
    msg.header.frame_id = frame_id
    return msg

listener = None
tfBuffer = None

def mapping_odom2(odom : mars_message.Odometry, frame_id):
    msg = nav_msgs.msg.Odometry()
    p = (odom.pose.pose)
    q = (odom.pose.orientation)
    transform_map_base = t.concatenate_matrices(t.translation_matrix([p.x, p.y, p.z]), t.quaternion_matrix([q.x, q.y, q.z, q.w]))
    #transform_base_map = t.inverse_matrix(transform_map_base)
    print("map",odom.pose.pose.x,odom.pose.pose.y,odom.pose.pose.z)
    global listener
    global tfBuffer


    if listener == None:
        tfBuffer = tf2_ros.Buffer()
        listener = tf2_ros.TransformListener(tfBuffer)
    try:
        trans=tfBuffer.lookup_transform("odom", "base_link", mapping_stamp(odom.timestampMs-200))
        p = trans.transform.translation
        q = trans.transform.rotation
        print("odom",trans.transform.translation.x,trans.transform.translation.y,trans.transform.translation.z)
        
        transform_odom_base = t.concatenate_matrices(t.translation_matrix([p.x, p.y, p.z]), t.quaternion_matrix([q.x, q.y, q.z, q.w]))
        transform_base_odom = t.inverse_matrix(transform_odom_base)
        #transform_odom_map = transform_odom_base * transform_base_map
        #transform_map_odom = t.inverse_matrix(transform_odom_map)
        transform_map_odom = transform_map_base * transform_base_odom

        translation = t.translation_from_matrix(transform_map_odom)
        quaternion = t.quaternion_from_matrix(transform_map_odom)
        (r, pitch, y) = tf.transformations.euler_from_quaternion(quaternion)
        qq = tf.transformations.quaternion_from_euler(0, 0, y)
        
        br = tf2_ros.TransformBroadcaster()  # 定义 TF 变换广播者
        trs = geometry_msgs.msg.TransformStamped()  # 定义广播者要广播的数据类型
        trs.header.stamp = mapping_stamp(odom.timestampMs)
        trs.header.frame_id = frame_id
        trs.child_frame_id = "odom"
        trs.transform.translation.x = translation[0]
        trs.transform.translation.y = translation[1]
        trs.transform.translation.z = translation[2]
        print("base",translation[0],translation[1],translation[2])
        # 从偏航角解算出对应的四元数，只考虑平面运动
        (r, p, y) = tf.transformations.euler_from_quaternion([odom.pose.orientation.x, odom.pose.orientation.y, odom.pose.orientation.z, odom.pose.orientation.w])
        q = tf.transformations.quaternion_from_euler(0, 0, -y)
        trs.transform.rotation.x = qq[0]
        trs.transform.rotation.y = qq[1]
        trs.transform.rotation.z = qq[2]
        trs.transform.rotation.w = qq[3]
        br.sendTransform(trs)



        msg.pose.pose.position.x = translation[0]
        msg.pose.pose.position.y = translation[1]
        msg.pose.pose.position.z = translation[2]
        msg.pose.pose.orientation.x = qq[0]
        msg.pose.pose.orientation.y = qq[1]
        msg.pose.pose.orientation.z = qq[2]
        msg.pose.pose.orientation.w = qq[3]

        msg.twist.twist.angular.x = 0
        msg.twist.twist.angular.y = 0
        msg.twist.twist.angular.z = 0
    except Exception as e:
        print(e)

	# 发布里程计信息
    msg.header.frame_id = frame_id
    msg.child_frame_id = "base_link"
    msg.header.stamp = mapping_stamp(odom.timestampMs)
	

    return msg


def mapping_color(color : mars_message.ColorRGBA):
    msg = std_msgs.msg.ColorRGBA()
    msg.r = color.r
    msg.b = color.b
    msg.g = color.g
    msg.a = color.a
    return msg

def mapping_marker(marker : mars_message.Marker, frame_id):
    msg = visualization_msgs.msg.Marker()
    msg.ns = marker.ns
    msg.id = marker.id
    msg.type = marker.type
    msg.action = marker.action
    msg.pose = mapping_pose(marker.pose)
    msg.scale = mapping_vector3(marker.scale)
    msg.color = mapping_color(marker.color)
    msg.lifetime.from_sec(marker.lifetime/1000.0)
    msg.frame_locked = False
    for p in marker.points:
        point = mapping_point(p)
        msg.points.append(point)
    for c in marker.colors:
        msg.colors.append(mapping_color(c))
    msg.header.frame_id = frame_id
    msg.header.stamp = mapping_stamp(marker.timestampMs)
    return msg

def mapping_odom(odom : mars_message.Odometry, frame_id):
    msg = nav_msgs.msg.Odometry()
    # 发布 TF 变换
    br = tf2_ros.TransformBroadcaster()  # 定义 TF 变换广播者
    trans = geometry_msgs.msg.TransformStamped()  # 定义广播者要广播的数据类型
	# TF transform  odom->base_link
    trans.header.stamp = mapping_stamp(odom.timestampMs)
    trans.header.frame_id = frame_id
    trans.child_frame_id = "base_link"
    trans.transform.translation.x = odom.pose.pose.x
    trans.transform.translation.y = odom.pose.pose.y
    trans.transform.translation.z = odom.pose.pose.z
	# 从偏航角解算出对应的四元数，只考虑平面运动
    trans.transform.rotation.x = odom.pose.orientation.x
    trans.transform.rotation.y = odom.pose.orientation.y
    trans.transform.rotation.z = odom.pose.orientation.z
    trans.transform.rotation.w = odom.pose.orientation.w
    br.sendTransform(trans)


	# 发布里程计信息
    msg.header.frame_id = frame_id
    msg.header.stamp = mapping_stamp(odom.timestampMs)
    msg.child_frame_id = "base_link"
	
    msg.pose.pose.position.x = odom.pose.pose.x
    msg.pose.pose.position.y = odom.pose.pose.y
    msg.pose.pose.position.z = odom.pose.pose.z
    msg.pose.pose.orientation.x = odom.pose.orientation.x
    msg.pose.pose.orientation.y = odom.pose.orientation.y
    msg.pose.pose.orientation.z = odom.pose.orientation.z
    msg.pose.pose.orientation.w = odom.pose.orientation.w
	
    msg.twist.twist.linear.x = odom.linearVelocity.x
    msg.twist.twist.linear.y = odom.linearVelocity.y
    msg.twist.twist.linear.z = odom.linearVelocity.z
    msg.twist.twist.angular.x = odom.angularVelocity.x
    msg.twist.twist.angular.y = odom.angularVelocity.y
    msg.twist.twist.angular.z = odom.angularVelocity.z
    return msg

class LcmMapping(object):
     def __init__(self, topic, ros_topic, lcm_type, ros_type, frame, to_ros):
        self.topic = topic
        self.ros_topic = ros_topic
        self.lcm_type = lcm_type
        self.ros_type = ros_type
        self.frame = frame
        self.to_ros = to_ros
    
lcm_mapping = [
    # LcmMapping("RobotSpeed", "/sweeper_drive_controller/cmd_vel",mars_message.Twist, geometry_msgs.msg.Twist, "base_link", mapping_speed),
    # LcmMapping("Scan*", "Scan*", mars_message.PointCloud2, sensor_msgs.msg.PointCloud, "lidar_link", mapping_pointcloud),
    # LcmMapping("PL*", "PL*", mars_message.PointCloud, sensor_msgs.msg.PointCloud, "base_link", mapping_pointcloud),
    # LcmMapping("PG*", "PG*", mars_message.PointCloud, sensor_msgs.msg.PointCloud, "odom", mapping_pointcloud),
    # LcmMapping("Imu", "Imu",mars_message.Imu, sensor_msgs.msg.Imu, "base_link", mapping_imu),
    # LcmMapping("Odom", "Odom",mars_message.Odometry, nav_msgs.msg.Odometry, "odom", mapping_odom),
    # LcmMapping("Map*", "MAP*",mars_message.GridMap, nav_msgs.msg.OccupancyGrid, "odom", mapping_map),
    # LcmMapping("Path*", "PATH*",mars_message.Path, nav_msgs.msg.Path, "odom", mapping_path),
    # LcmMapping("Marker*", "Marker*",mars_message.Marker, visualization_msgs.msg.Marker, "base_link", mapping_marker),
    LcmMapping("RobotSpeed", "/sweeper_drive_controller/cmd_vel",mars_message.Twist, geometry_msgs.msg.Twist, "base_link", mapping_speed),
    #LcmMapping("SCAN","SCAN", mars_message.LaserScan, sensor_msgs.msg.LaserScan, "lidar_link", mapping_scan),
    LcmMapping("global_cloud", "global_cloud", mars_message.PointCloud2, sensor_msgs.msg.PointCloud, "odom", mapping_pointcloud),
    LcmMapping("SCAN", "SCAN", mars_message.PointCloud2, sensor_msgs.msg.PointCloud, "lidar_link", mapping_pointcloud),
    LcmMapping("SCANRAW", "SCANRAW", mars_message.PointCloud2, sensor_msgs.msg.PointCloud, "lidar_link", mapping_pointcloud),
    LcmMapping("OBS", "OBS", mars_message.PointCloud, sensor_msgs.msg.PointCloud, "base_link", mapping_pointcloud),
    LcmMapping("ZOBS", "ZOBS", mars_message.PointCloud, sensor_msgs.msg.PointCloud, "odom", mapping_pointcloud),
    LcmMapping("AOBS", "AOBS", mars_message.PointCloud, sensor_msgs.msg.PointCloud, "odom", mapping_pointcloud),
    LcmMapping("COBS", "COBS", mars_message.PointCloud, sensor_msgs.msg.PointCloud, "odom", mapping_pointcloud),
    LcmMapping("GOBS", "GOBS", mars_message.PointCloud, sensor_msgs.msg.PointCloud, "odom", mapping_pointcloud),
    LcmMapping("VOBS", "VOBS", mars_message.PointCloud, sensor_msgs.msg.PointCloud, "odom", mapping_pointcloud),
    LcmMapping("DOORS", "DOORS", mars_message.PointCloud, sensor_msgs.msg.PointCloud, "odom", mapping_pointcloud),
    LcmMapping("TIMEOBS", "TIMEOBS",mars_message.PointCloud, sensor_msgs.msg.PointCloud, "odom", mapping_pointcloud),
    LcmMapping("SCAN1D_0", "SCAN1D_0",mars_message.PointCloud2, sensor_msgs.msg.PointCloud, "scan1d_right", mapping_pointcloud),
    LcmMapping("SCAN1D_1", "SCAN1D_1",mars_message.PointCloud2, sensor_msgs.msg.PointCloud, "scan1d_left", mapping_pointcloud),
    LcmMapping("SCAN1D_2", "SCAN1D_2",mars_message.PointCloud2, sensor_msgs.msg.PointCloud, "scan1d_center", mapping_pointcloud),
    LcmMapping("IMU", "IMU",mars_message.Imu, sensor_msgs.msg.Imu, "body", mapping_imu),
    LcmMapping("ODOM", "ODOM",mars_message.Odometry, nav_msgs.msg.Odometry, "odom", mapping_odom),
    LcmMapping("MAP", "MAP",mars_message.GridMap, nav_msgs.msg.OccupancyGrid, "odom", mapping_map),
    LcmMapping("APPMAP", "APPMAP",mars_message.GridMap, nav_msgs.msg.OccupancyGrid, "odom", mapping_map),
    LcmMapping("NAVIPATH", "NAVIPATH",mars_message.Path, nav_msgs.msg.Path, "odom", mapping_path),
    LcmMapping("NAVIPATH2", "NAVIPATH2",mars_message.Path, nav_msgs.msg.Path, "odom", mapping_path),
    LcmMapping("DWAPATH", "DWAPATH",mars_message.Path, nav_msgs.msg.Path, "odom", mapping_path),
    LcmMapping("LOCAL", "LOCAL",mars_message.Path, nav_msgs.msg.Path, "odom", mapping_path),
    LcmMapping("CLEANPATH", "CLEANPATH",mars_message.Path, nav_msgs.msg.Path, "odom", mapping_path),
    LcmMapping("LaserMarker", "LaserMarker",mars_message.Marker, visualization_msgs.msg.Marker, "lidar_link", mapping_marker),
    LcmMapping("MarkerPlanTo", "MarkerPlanTo",mars_message.Marker, visualization_msgs.msg.Marker, "odom", mapping_marker),
    LcmMapping("DoorsMarker", "DoorsMarker",mars_message.Marker, visualization_msgs.msg.Marker, "odom", mapping_marker),
]

def lcm_message_handler(channel, data):
    mapping = lcm_mappings[channel]
    msg = mapping.lcm_type.decode(data)
    ros_msg = mapping.to_ros(msg, mapping.frame)
    pub = rospy.Publisher(channel, mapping.ros_type, queue_size = 10)
    pub.publish(ros_msg)

def main():

    signal.signal(signal.SIGINT, signal_handler)

    rospy.init_node("lcm2ros")
    for t in lcm_mapping:
        lcm_pubs[t.topic] = rospy.Publisher(t.ros_topic, t.ros_type, queue_size = 10)
        lcm_mappings[t.topic] = t
    
    lc = lcm.LCM()
    subscriptions = []
    for t in lcm_mapping:
        subscriptions.append(lc.subscribe(t.topic, lcm_message_handler))
    
    while not rospy.is_shutdown():
        try:
            rfds, wfds, efds = select.select([lc.fileno()], [], [], 0.01)
            if rfds:
                lc.handle()
        except KeyboardInterrupt:
            break
    for s in subscriptions:
        lc.unsubscribe(s)
if __name__ == "__main__":
    main()
