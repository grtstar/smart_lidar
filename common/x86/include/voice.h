#pragma once

enum
{
    PLAY_QUEUE,     // 等待前一个语音播放完成后播放
    PLAY_INTERUPT,  // 播放时,打断前一个未播放完的语音
    PLAY_TOGETHER   // 和前一个未播放完成的语音一起播放
};

#define V_BUTTON_BEEP           500

#define V_POWEROFF              0   //暂无定义

#define V_WIFI_RECV_PWD         0   //暂无定义
#define V_LIDAR1D_ERROR         0   //暂无定义
#define V_GUNTONG_ERROR         0   //暂无定义

#define V_DUSTBOX_ERROR             101     // 尘盒未安装，请安装
#define V_DUSTBOX_FULL              102     // 尘盒已满，请清理
#define V_MAINBRUSH_ERROR           103     // 滚刷卡住，请取下并清理
#define V_SIDEBRUSH_ERROR           104     // 边刷卡住，请拆卸并清理
#define V_LWHEEL_ERROR              105     // 主轮卡住，请检查是否有异物
#define V_RWHEEL_ERROR              105     // 主轮卡住，请检查是否有异物
#define V_BUMPER_ERROR              106     // 前方碰撞缓冲器故障，请轻拍清除异物
#define V_FRONT_PROXIMITY           107     // 前方碰撞缓冲器故障，请擦拭脏污
#define V_CLIFF_SENSOR              108     // 防跌落传感器故障，请擦拭脏污
#define V_CLIFF_ERROR               109     // 机器悬空，请将机器置于安全位置
#define V_HANGUP_ERROR              109     // 机器悬空，请将机器置于安全位置
#define V_POWER_IS_OFF              110     // 电源未打开，请打开侧方电源开关
#define V_LIDAR_ERROR               111     // 雷达被卡住，请清除异物
#define V_LIDAR_BLIND               112     // 雷达被挡住，请擦拭激光传感器镜片
#define V_BUTTON                    113     // 按键故障，请尝试重新按下按键
#define V_FAN_ERROR                 114     // 吸尘风机被卡住，请联系售后处理
#define V_GYRO                      115     // 陀螺仪故障，请关闭电源后重新开机
#define V_COMMUNICATE_ERROR         116     // 通讯异常，请关闭电源后重新开机
#define V_BATTERY_HIGH              117     // 电池温度过高，请关闭电源后重新开机
#define V_ROBOT_TRAPPED             118     // 机器被困住，请移动新位置重新启动
#define V_CHARGE_FULL               119     // 找不到充电座，请将机器放在电座上进行充电
#define V_EDGE_ERROR                120     // 沿边传感器故障，请及时处理
#define V_ULTRASOUND                121     // 超声波传感器故障，请及时处理
#define V_LIDAR_BUMPER_ERROR        122     // 雷达防撞传感器卡住了，请及时处理
#define V_LIDAR_NO_CALI             123     // 雷达未校准,TTS合成
#define V_BATTERY_LOW_SHUTTING_DOWN 124     // 电量过低，机器即将关机
#define V_ROBOT_IN_FORBID           125     // 机器在禁区中，无法启动
#define V_WATERTANK_IN_CARPET       126     // 安装拖地板在地毯上无法启动，请拆卸水箱后再进行地毯清扫
#define V_MOP_ERROR                 127     // 拖布未安装完整
#define V_NO_CLEAN_TANK             128     // 清水箱未安装，请安装
#define V_WATER_NOT_ENOUGH          129     // 清水箱水量不足，请加水
#define V_NO_SEWAGE_TANK            130     // 污水箱未安装，请安装
#define V_SEWAGE_TANK_FULL          131     // 污水箱已满，请处理
#define V_LEFF_CLOTH_OVERLOAD       132     // 左边拖布过载
#define V_RIGHT_CLOTH_OVERLOAD      133     // 右边拖布过载
#define V_MOP_CTRL_ERROR            134     // 拖布控制异常

#define V_SYSTEM_START              201     // 系统启动中，请稍等
#define V_WIFI_CONFIG               202     // WiFi已重置
#define V_WIFI_CONNECTED            203     // 设备联网中
#define V_SERVER_CONNECTED          204     // 设备联网成功
#define V_BATTERY_LOW_CHARGE        205     // 电量过低，返回充电
#define V_START_CLEAN               206     // 开始清扫
#define V_GO_CHARGE                 207     // 开始回充
#define V_ORDER_SET                 208     // 预约成功
#define V_ORDER_CANCEL              209     // 取消/关闭预约
#define V_POWER_ON                  210     // 系统启动完成
#define V_PAUSE_CLEAN               211     // 暂停清扫
#define V_ZONE_CLEAN                212     // 开始区域清扫
#define V_CONTINUE_CLEAN            213     // 继续清扫
#define V_CHARGEING                 214     // 充电中
#define V_CHARGE_COMPLETE           215     // 充电完成
#define V_START_UPDATE              216     // 开始系统升级
#define V_UPDATE_SUCC               217     // 系统升级成功
#define V_UPDATE_FAIL               218     // 系统升级失败
#define V_MCU_UPGRADE               219     // 开始MCU升级
#define V_MCU_UPGRADE_SUCCESS       220     // MCU升级成功
#define V_MCU_UPGRADE_FAIL          221     // MCU升级失败
#define V_WIFI_FAIL                 222     // 网络连接失败，密码错误
#define V_WIFI_UNKNOWN_ERR          223     // 网络连接失败，请检查路由器配置
#define V_WIFI_NOTFOUND             224     // 网络连接失败，找不到路由器
#define V_VOLUME_UP                 225     // 音量增加
#define V_VOLUME_DOWN               226     // 音量减小
#define V_SEEK_ROBOT                227     // 我在这里
#define V_FINISH_CLEAN              228     // 清扫完成,返回充电
#define V_RELOCATE_START            229     // 开始重新定位
#define V_RELOCATE_FAIL             230     // 重新定位失败

#define V_ROOM_CLEAN                231     // 开始分区清扫
#define V_START_SPOT_CLEAN          232     // 开始重点清扫
#define V_RESTART_ZONE_DIVIDE       233     // 开始重新分区
#define V_OPEN_ZONE_FUNCTION        234     // 开启智能分区
#define V_CLOSE_ZONE_FUNCTION       235     // 关闭智能分区
#define V_SPOT_CLEAN                236     // 强力模式
#define V_MODE_CUTE                 237     // 静音模式
#define V_MODE_NORMAL               238     // 标准模式
#define V_STOP_CLEAN                239     // 结束清扫
#define V_ADD_MAP                   240     // 新增地图
#define V_SAVE_MAP                  241     // 保存地图
#define V_SWITCH_MAP                242     // 切换地图
#define V_DELETE_MAP                243     // 删除地图
#define V_RELOCATE_SUCC             244     // 重新定位成功

#define V_DUSTBAG_FULL              245     // 集尘尘满(0x63)
#define V_DUSTBAG_FAULT             246     // 未安装集尘袋(0x6d)
#define V_DUSTCOLLECTOR_NOT_COVER   247     // 没盖盖子(0x6c)
#define V_DUSTCOLLECTOR_BLOCK       248     // 风压阻塞(0x6b)
#define V_DUSTCOLLECTOR_ERROR       249     // 集尘错误(0x62)
#define V_DUST_COLLECTING           250     // 集尘中
#define V_START_DUST_COLLECTING     254     // 准备开始集尘
#define V_COLLECTING_FINISHED       255     // 已经完成集尘

#define V_QUICK_MAPPING             256     // 开始快速建图
#define V_QMAP_PAUSE                257     // 暂停建图
#define V_QMAP_SUCC                 258     // 建图已完成，请在APP中查看
#define V_QMAP_FAIL                 0       // 暂无定义
#define V_START_MOP_MODE            259     // 开始扫拖，请确保清水箱水量充足
#define V_START_CLEANING_MOP        260     // 开始清洗拖布和补水
#define V_REBACK_RECLEAN            261     // 返回基站清洗拖布
#define V_START_STOVING_MOP         262     // 开始烘干拖布
#define V_FINISH_STOVING_MOP        263     // 完成烘干拖布
#define V_FINISH_TO_REBACK          264     // 清洁完成，返回充电，请及时清理污水箱
#define V_SWEEP_FLOOR               265     // 进入扫地模式
#define V_SWEEP_MOP                 266     // 进入扫拖模式
#define V_MOP_ONLY                  267     // 进入仅拖模式
#define V_START_DOCK_CLEAN          268     // 开始基站自清洁

//本来是都要全部大写，为了读起来方便，暂时用大驼峰
#define V_LidarCalibrationSucceeded 301//雷达校准成功
#define V_LidarCalibrationFailed    302//雷达校准失败
#define V_EnterIntoTestMode         305//进入测试模式
#define V_Duang                     304//duang,用于测试中间语音提示
#define V_CollisionAndDropTest      306//碰撞和跌落测试
#define V_LidarTest                 307//leida ceshi 
#define V_BaseComponentTest         308//底盘部件测试
#define V_FanMotorTest              312//风机测试
#define V_Start                     309//开始
#define V_Fail                      310//失败
#define V_Pass                      311//通过

#define V_DingDong                  500//叮咚语音