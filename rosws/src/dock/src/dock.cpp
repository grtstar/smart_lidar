#include "ros/ros.h"
#include "tf/tf.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/Range.h"
#include "gazebo_msgs/ContactsState.h"
#include "geometry_msgs/Vector3.h"
#include "std_msgs/UInt8MultiArray.h"

uint8_t _irCode[4] = {0};
ros::Publisher vPub;
ros::Publisher bmpPub;
ros::Publisher ZeroSpdPub;

#define COLOR_HIGH  170
#define COLOR_LOW   20

ros::Time SpeedTime;

void CameraLeftCallback(const sensor_msgs::Image::ConstPtr &msg)
{
    uint8_t r, g, b;
    uint8_t mask = 0;
    for (int h = 0; h < msg->height; h++)
    {
        for (int w = 0; w < msg->width; w++)
        {
            r = msg->data[0 + w * h * 3];
            g = msg->data[1 + w * h * 3];
            b = msg->data[2 + w * h * 3];
            if (r > COLOR_HIGH && g < COLOR_LOW && b < COLOR_LOW) // r, 前左
            {
                mask |= 1;
            }
            if (r < COLOR_LOW && g > COLOR_HIGH && b < COLOR_LOW) // g，前右
            {
                mask |= 2;
            }
            if (r < COLOR_LOW && g < COLOR_LOW && b > COLOR_HIGH) // b，左
            {
                mask |= 4;
            }
            if (r > COLOR_HIGH && g < COLOR_LOW && b > COLOR_HIGH) // purple，右
            {
                mask |= 8;
            }
        }
    }
    for(int i=0; i<4; i++)
    {
        if(mask & (1<<i))
        {
            _irCode[i] = 0xA3;
        }
        else if(_irCode[i] == 0xA3)
        {
            _irCode[i] = 0;
        }
    }

    if (mask)
    {
        std_msgs::UInt8MultiArray m;
        m.data.push_back(_irCode[0]);
        m.data.push_back(_irCode[1]);
        m.data.push_back(_irCode[2]);
        m.data.push_back(_irCode[3]);
        vPub.publish(m);
    }
}

void CameraRightCallback(const sensor_msgs::Image::ConstPtr &msg)
{
    uint8_t r, g, b;
    uint8_t mask = 0;
    for (int h = 0; h < msg->height; h++)
    {
        for (int w = 0; w < msg->width; w++)
        {
            r = msg->data[0 + w * h * 3];
            g = msg->data[1 + w * h * 3];
            b = msg->data[2 + w * h * 3];
            if (r > COLOR_HIGH && g < COLOR_LOW && b < COLOR_LOW) // r, 前左
            {
                mask |= 1;
            }
            if (r < COLOR_LOW && g > COLOR_HIGH && b < COLOR_LOW) // g，前右
            {
                mask |= 2;
            }
            if (r < COLOR_LOW && g < COLOR_LOW && b > COLOR_HIGH) // b，左
            {
                mask |= 4;
            }
            if (r > COLOR_HIGH && g < COLOR_LOW && b > COLOR_HIGH) // purple，右
            {
                mask |= 8;
            }
        }
    }
    for(int i=0; i<4; i++)
    {
        if(mask & (1<<i))
        {
            _irCode[i] = 0xA4;
        }
        else if(_irCode[i] == 0xA4)
        {
            _irCode[i] = 0;
        }
    }

    if (mask)
    {
        std_msgs::UInt8MultiArray m;
        m.data.push_back(_irCode[0]);
        m.data.push_back(_irCode[1]);
        m.data.push_back(_irCode[2]);
        m.data.push_back(_irCode[3]);
        vPub.publish(m);
    }
}


void BumperCallback(const gazebo_msgs::ContactsStatePtr msg)
{
    sensor_msgs::Range m;
    m.header = msg->header;
    if(msg->states.empty()) 
    {
        m.radiation_type = 0;
        m.field_of_view = 0;
        m.min_range = 0;
        m.max_range = 0;
        m.range = 0;
    }
    else
    {
        for(int i=0;i<msg->states.size();i++)
        {
            gazebo_msgs::ContactState state;
            state = msg->states.at(i);
            for(int j=0;j<state.contact_positions.size();j++)
            {
                geometry_msgs::Vector3 contact_position;
                contact_position = state.contact_positions.at(j);
                m.radiation_type = 0x4;
                m.field_of_view = contact_position.x;
                m.min_range = contact_position.y;
                m.max_range = contact_position.z;
                m.range = 0;
            }
        }
    }
    bmpPub.publish(m);
}

void SpeedCallback(const geometry_msgs::TwistPtr msg)
{
    SpeedTime = ros::Time::now();
}

void CheckSpeed()
{
    ros::Time NowTime;
    NowTime = ros::Time::now();
    ros::Duration diff = NowTime-SpeedTime;
    double nsec = diff.toNSec()/1000000;
    //printf("Time:Spd:%ld :: Now:%ld :: diff: %lf \n",(SpeedTime.toNSec()/1000000),(NowTime.toNSec()/1000000),nsec);
    if(nsec > 500)
    {
        geometry_msgs::Twist Spd;
        Spd.angular.x = 0;
        Spd.angular.y = 0;
        Spd.angular.z = 0;
        Spd.linear.x = 0;
        Spd.linear.y = 0;
        Spd.linear.z = 0;
        ZeroSpdPub.publish(Spd);
    }
}

// if (contact_position.x > 0.01)
// {
//     if (contact_position.y >= 0.06) {m.field_of_view = 0x2;}
//     else if (contact_position.y <= -0.06) {m.field_of_view = 0x1;}
//     else {m.field_of_view = 0x3;}
//     bmpPub.publish(m);
// }
// else 
// {
//     m.field_of_view = 0;
// }

int main(int argc, char **argv)
{
    ros::init(argc, argv, "dock");
    ros::NodeHandle n;
    ros::Subscriber subLeft = n.subscribe("/dock/left/image_raw", 1, CameraLeftCallback);
    ros::Subscriber subRight = n.subscribe("/dock/right/image_raw", 1, CameraRightCallback);
    vPub = n.advertise<std_msgs::UInt8MultiArray>("/ircode", 1);

    ros::Subscriber bumper = n.subscribe("/bumper", 1, BumperCallback);
    bmpPub = n.advertise<sensor_msgs::Range>("/lcmbumper", 1);

    ros::Subscriber ZeroSpd = n.subscribe("/sweeper_drive_controller/cmd_vel", 1, SpeedCallback);
    ZeroSpdPub = n.advertise<geometry_msgs::Twist>("/sweeper_drive_controller/cmd_vel", 1);

    ros::Rate loop_rate(100);

    /**
     * A count of how many messages we have sent. This is used to create
     * a unique string for each message.
     */
    while (ros::ok())
    {
        CheckSpeed();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}