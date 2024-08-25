#pragma once

#include <string>
/**
 * @brief 使用单字节字符串的枚举消息,跨进程消息通讯中使用
 * 可避免由于不同程序中增删定义导致的 enum 值不一致
 * 同时 enum 值可以携带一定语义,方便打印调试
 * 定义时需要保证字符个数小于等于 4 个字符
 * 
 */
typedef enum RobotMessage
{
    MSG_POWER_OFF = 'POFF',
    MSG_SLEEP = 'SLEP',
    MSG_CLEAN_KEY = 'CKEY',
    MSG_CLEAN_START = 'CSTT',
    MSG_CLEAN_PAUSE = 'CPAU',
    MSG_CLEAN_STOP = 'CSTP',
    MSG_HOME_KEY = 'HOME',
    MSG_QUICK_MAPPING = 'QMAP',
    MSG_RESET_MAP = 'RSTM',
    MSG_RESET_WIFI = 'RNET',
    MSG_RESET_SYSTEM = 'RSYS',
}RobotMessage;

typedef enum CleanMode
{
    CM_AUTO = 'AUTO',
    CM_GOTO_CHARGE = 'CHRG',
    CM_ZONE = 'ZONE',
    CM_POSE = 'POSE',
    CM_PART = 'PART',
    CM_ROOM = 'ROOM',
}CleanMode;

typedef enum CleanStatus
{
    CS_STANDBY = 'STBY',
    CS_AUTO = 'AUTO',
    CS_ZONE_CLEAN = 'ZONE',
    CS_PART_CLEAN = 'PART',
    CS_GOTO_POS = 'GPOS',
    CS_POS_ARRIVED='ARRV',
    CS_POS_UNARRIVE='UNAR',
    CS_PAUSE = 'PAUS',
    CS_GOTO_CHARGE = 'GOCH',
    CS_CHARGING = 'CHRG',
    CS_COLLECTING_DUST = 'DUST'
}CleanStatus;

typedef enum CleanPower
{
    PWR_CLOSED = 'CLOS',
    PWR_SOFT = 'SOFT',
    PWR_NORMAL = 'NORM',
    PWR_STRONG = 'STRO',
    PWR_MAX = 'MAX'
}CleanPower;

static std::string M2S(int msg)
{
    if(msg == 0)
    {
        return "OFF";
    }
    std::string s;
    s.push_back(msg>>24);
    s.push_back(msg>>16);
    s.push_back(msg>>8);
    s.push_back(msg>>0);
    s.push_back(0);
    return s;
}