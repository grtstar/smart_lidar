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
    MSG_HOME_STOP = 'HSTP',
    MSG_QUICK_MAPPING = 'QMAP',
    MSG_RESET_MAP = 'RSTM',
    MSG_SAVE_MAP = 'SAVM',
    MSG_DELETE_MAP = 'DELM',
    MSG_SWITCH_MAP = 'SWIM',
    MSG_LOCATION_LOST ='LOCL',
    MSG_RESET_WIFI = 'RNET',
    MSG_RESET_SYSTEM = 'RSYS',
    MSG_RELOCATE_START = 'RLOC',
    MSG_RELOCATE_SUCC = 'RLOK',
    MSG_RELOCATE_FAIL = 'RLNG',
    MSG_NO_RELOCATE = 'NORL',
    MSG_LIDAR_POWER = 'LPWR',
    MSG_MANUAL_FORWARD = 'MFWR',
    MSG_MANUAL_BACK = 'MBCK',
    MSG_MANUAL_LEFT = 'MLT',
    MSG_MANUAL_RIGHT = 'MRT',
    MSG_MANUAL_STOP = 'MSTP',
    MSG_CHILD_LOCK = 'MLCK',
    MSG_START_TASK = 'TASK',
    MSG_FACOTRY_SCAN1D = 'FS1D',
    MSG_HOME_CLEAN_KEY ='MHCK',
    MSG_FACOTRY_START = 'FSTR',
    MSG_LIDAR_CORR_START ='LCST',
    MSG_LIDAR_CORR_SUCC ='LCSU',
    MSG_LIDAR_CORR_FAIL ='LCFA',
    MSG_LIDAR_CORR_TIMEOUT = 'LCTO',
    MSG_ON_CHAGE = 'ONCH',
    MSG_OFF_CHAGE = 'OFCH',
    MSG_NORMAL = 'NORM',
    MSG_LOW_BATTERY = 'LOBT',
    MSG_CHAGE_DONE = 'CHDO',
    MSG_ERROR = 'MERR',
    MSG_WIFI_NOTCONNECTED = 'WFNC',
    MSG_WIFI_SOFTAP = 'WFAP',
    MSG_WIFI_CONNECTING = 'WFCG',
    MSG_WIFI_CONNECTED = 'WFCD',
    MSG_WIFI_ERROR = 'WFER',
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
    CS_ROOM = 'ROOM',
    CS_POS_ARRIVED='ARRV',
    CS_POS_UNARRIVE='UNAR',
    CS_PAUSE = 'PAUS',
    CS_GOTO_CHARGE = 'GOCH',
    CS_CHARGING = 'CHRG',
    CS_CHARGE_DONE = 'CHRD',
    CS_COLLECTING_DUST = 'DUST',
    CS_SELF_CLEAN = 'SCLN',
    CS_MAPPING = 'MAPG',
    CS_MAPPING_DONE = 'MAPD',

}CleanStatus;

typedef enum CleanPower
{
    PWR_CLOSED = 'CLOS',
    PWR_SOFT = 'SOFT',
    PWR_NORMAL = 'NORM',
    PWR_STRONG = 'STRO',
    PWR_MAX = 'MAX'
}CleanPower;

typedef enum CleanMethod
{
    CM_BOTH = 'CBTH',
    CM_SWEEP = 'CSWP',
    CM_MOP = 'CMOP',
    CM_MOVE = 'CMOV',
    CM_STOP = 'CSTP',
    CM_SELFCLEAN ='CCLN',
}CleanMethod;

typedef enum CleanModule
{
    FAN = 'MFAN',
    MBRUSH = 'MBRH',
    WATERPUMP = 'MWPM',
    AIRPUMP = 'MAPM',
    GTRPM = 'MGTR',
    MODULEALL = 'MDAL'
}CleanModule;


enum
{
    ERROR_SIDE_BRUSH,
    ERROR_MAIN_BRUSH,
    ERROR_LEFT_WHEEL,
    ERROR_RIGHT_WHEEL,
    ERROR_WHEEL_HANGUP,
    ERROR_DUST_BOX,
    ERROR_CLIFF,
    ERROR_BUMPER,
    ERROR_FAN,
    ERROR_GUN_TONG,
    ERROR_TRAPPED,
    ERROR_TRAPPED_IN_RESTICTED,
    ERROR_LIDAR,
    ERROR_LIDAR1D,
    ERROR_BATTERY_LOW,  //电量过低，即将关机
    ERROR_CHARGE_FAIL,
    ERROR_COMM_ERROR,
};

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

static int32_t S2M(std::string msg)
{
    if(msg.empty())
    {
        return 0;
    }
    int32_t m = 0;
    for(int i=0; i<msg.length();i++)
    {
        m <<= 8;
        m |= msg.at(i);
    }
    return m;
}

static std::string D2H(int num)
{
    std::string hex;
    char map[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(num > 0)
    {
        hex = map[num & 0xF] + hex; // 取低四位，并拼接到字符串开头
        num >>= 4; // 右移四位
    }
    hex = std::string(2-hex.size(),'0') + hex;
    return hex;
}
