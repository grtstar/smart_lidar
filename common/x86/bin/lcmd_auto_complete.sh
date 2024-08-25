
_lcmd()  
{  
    COMPREPLY=()  
    local cur=${COMP_WORDS[COMP_CWORD]};  
    local cmd=${COMP_WORDS[COMP_CWORD-1]};  
    case $cmd in  
    'lcmd')  
          COMPREPLY=( $(compgen -W '-h -p -m' -- $cur) ) ;;  
    '*')  
          ;;  
    esac  
    if [[ ${COMP_CWORD} -eq 3 ]]; then  
          COMPREPLY=($(compgen -W 'mars_message.AlarmInfo mars_message.AppCarpet mars_message.AppCleanInfo mars_message.AppCleanRecord mars_message.AppLocalAlert mars_message.AppMap mars_message.AppMisc mars_message.AppNotDisturbTime mars_message.AppPartitionDivision mars_message.AppPartitionMerge mars_message.AppPartsLife mars_message.AppPath mars_message.AppRestrictedArea mars_message.AppRoomClean mars_message.AppRoomProperties mars_message.AppSetCleaningSequence mars_message.AppSetRoomName mars_message.AppSetRoomProperties mars_message.AppSpotClean mars_message.AppVirtualWall mars_message.AppZoneClean mars_message.BlueToothInfo mars_message.BlueToothState mars_message.Bumper mars_message.ClearComponent mars_message.Coder mars_message.ColorRGBA mars_message.Debug mars_message.DevicePower mars_message.DoorInfo mars_message.Event mars_message.FactoryTestConfig mars_message.FusionPose mars_message.GridMap mars_message.IO mars_message.Imu mars_message.IrCode mars_message.IrCode2 mars_message.LaserScan mars_message.MacAddrCode mars_message.MapRect mars_message.Marker mars_message.ObsAvoidance mars_message.Odometry mars_message.OverloadConfig mars_message.PartsLifeConfig mars_message.Path mars_message.Point mars_message.PointCloud mars_message.PointCloud2 mars_message.Polygon mars_message.Pose mars_message.Quaternion mars_message.Range mars_message.Ranges mars_message.RobotStatus mars_message.RoomInfo mars_message.RoomPropety mars_message.Segment mars_message.Shell mars_message.Speed mars_message.SweeperStatus mars_message.TimedTaskInfo mars_message.Twist mars_message.Vector3 ' -- $cur))  
    fi  
    if [[ "${COMP_WORDS[1]}" == "-p" && ${COMP_CWORD} -eq 4 ]]; then  
    case $cmd in  
          'mars_message.AlarmInfo')
COMPREPLY="'
{
    \"appName\": \"\",
    \"logType\": \"\",
    \"logValue\": \"\"
}
'";;
'mars_message.AppCarpet')
COMPREPLY="'
{
    \"version\": 0,
    \"count\": 0,
    \"type\": [],
    \"carpet\": []
}
'";;
'mars_message.AppCleanInfo')
COMPREPLY="'
{
    \"cleanTimeSecond\": 0,
    \"cleanArea\": 0.0,
    \"cleanTimeTotalSecond\": 0,
    \"cleanAreaTotal\": 0.0,
    \"cleanCountTotal\": 0,
    \"esimateArea\": 0.0,
    \"carpetArea\": 0.0,
    \"numberOfTasksCompleted\": 0,
    \"sweepTimeTotalSecond\": 0,
    \"washTimeTotalSecond\": 0
}
'";;
'mars_message.AppCleanRecord')
COMPREPLY="'
{
    \"recordId\": 0,
    \"cleanTimeSecond\": 0,
    \"cleanArea\": 0.0,
    \"cleanMode\": 0,
    \"cleanMethod\": 0,
    \"finishResult\": 0,
    \"startReason\": 0
}
'";;
'mars_message.AppLocalAlert')
COMPREPLY="'
{
    \"verison\": 0,
    \"timeZone\": 0,
    \"number\": 0,
    \"timedTaskInfo\": []
}
'";;
'mars_message.AppMap')
COMPREPLY="'
{
    \"version\": 0,
    \"mapId\": 0,
    \"type\": 0,
    \"width\": 0,
    \"height\": 0,
    \"origin\": {
        \"pose\": {
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        },
        \"orientation\": {
            \"w\": 0.0,
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        }
    },
    \"resolution\": 0.0,
    \"charger\": {
        \"pose\": {
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        },
        \"orientation\": {
            \"w\": 0.0,
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        }
    },
    \"pointCount\": 0,
    \"data\": [],
    \"roomNum\": 0,
    \"roomPropeties\": [],
    \"roomName\": [],
    \"roomPolygon\": []
}
'";;
'mars_message.AppMisc')
COMPREPLY="'
{
    \"verison\": 0,
    \"enableNotDisturbTime\": 0,
    \"volume\": 0,
    \"enableContinueClean\": 0,
    \"language\": 0,
    \"dustCollctionNum\": 0,
    \"enbaleCustomizeMode\": 0,
    \"unitSet\": 0,
    \"carpetCleanPrefer\": 0,
    \"enableAutoBoost\": 0,
    \"enableChildLock\": 0
}
'";;
'mars_message.AppNotDisturbTime')
COMPREPLY="'
{
    \"version\": 0,
    \"onoff\": 0,
    \"timeZone\": 0,
    \"starTime\": 0,
    \"startDay\": 0,
    \"endTime\": 0,
    \"endDay\": 0
}
'";;
'mars_message.AppPartitionDivision')
COMPREPLY="'
{
    \"version\": 0,
    \"roomId\": 0,
    \"begin\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    },
    \"end\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    },
    \"ret\": 0
}
'";;
'mars_message.AppPartitionMerge')
COMPREPLY="'
{
    \"version\": 0,
    \"count\": 0,
    \"roomId\": [],
    \"ret\": 0
}
'";;
'mars_message.AppPartsLife')
COMPREPLY="'
{
    \"edgeBrushLifeMinutes\": 0,
    \"mainBrushLifeMinutes\": 0,
    \"haipaLifeMinutes\": 0,
    \"ragLifeMinutes\": 0
}
'";;
'mars_message.AppPath')
COMPREPLY="'
{
    \"id\": 0,
    \"count\": 0,
    \"points\": [],
    \"pointType\": [],
    \"degree\": 0.0
}
'";;
'mars_message.AppRestrictedArea')
COMPREPLY="'
{
    \"version\": 0,
    \"count\": 0,
    \"mode\": [],
    \"type\": [],
    \"polygon\": [],
    \"name\": []
}
'";;
'mars_message.AppRoomClean')
COMPREPLY="'
{
    \"version\": 0,
    \"cleanRepeat\": 0,
    \"count\": 0,
    \"id\": []
}
'";;
'mars_message.AppRoomProperties')
COMPREPLY="'
{
    \"roomId\": 0,
    \"cleanOrder\": 0,
    \"cleanRepeart\": 0,
    \"mopRepeat\": 0,
    \"colorOrder\": 0,
    \"donotSweep\": 0,
    \"donotMop\": 0,
    \"fanPower\": 0,
    \"waterLevel\": 0,
    \"enableYMop\": 0
}
'";;
'mars_message.AppSetCleaningSequence')
COMPREPLY="'
{
    \"version\": 0,
    \"count\": 0,
    \"roomId\": []
}
'";;
'mars_message.AppSetRoomName')
COMPREPLY="'
{
    \"version\": 0,
    \"count\": 0,
    \"roomId\": [],
    \"name\": []
}
'";;
'mars_message.AppSetRoomProperties')
COMPREPLY="'
{
    \"version\": 0,
    \"count\": 0,
    \"roomId\": [],
    \"fan\": [],
    \"waterLevel\": [],
    \"yMop\": [],
    \"cleanRepeat\": []
}
'";;
'mars_message.AppSpotClean')
COMPREPLY="'
{
    \"version\": 0,
    \"spot\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    },
    \"mode\": 0,
    \"suction\": 0,
    \"cistern\": 0,
    \"cleanRepeat\": 0
}
'";;
'mars_message.AppVirtualWall')
COMPREPLY="'
{
    \"version\": 0,
    \"count\": 0,
    \"mode\": [],
    \"wall\": []
}
'";;
'mars_message.AppZoneClean')
COMPREPLY="'
{
    \"version\": 0,
    \"count\": 0,
    \"zone\": [],
    \"name\": [],
    \"zoneID\": [],
    \"localSave\": [],
    \"type\": [],
    \"mode\": [],
    \"suction\": [],
    \"cistern\": [],
    \"cleanRepeat\": [],
    \"order\": []
}
'";;
'mars_message.BlueToothInfo')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"backpile\": false
}
'";;
'mars_message.BlueToothState')
COMPREPLY="'
{
    \"connect_state\": false
}
'";;
'mars_message.Bumper')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"count\": 0,
    \"mask\": 0
}
'";;
'mars_message.ClearComponent')
COMPREPLY="'
{
    \"reply\": 0,
    \"fanRpm\": 0,
    \"gtRpm\": 0,
    \"gtOffTime\": 0,
    \"gtOnDegree\": 0,
    \"gtCycle\": 0,
    \"gtCleanDegree\": 0,
    \"rbrushRpm\": 0,
    \"mbrushRpm\": 0,
    \"pumpOnTime\": 0,
    \"pumpOffTime\": 0,
    \"pump2OnTime\": 0,
    \"pump2OffTime\": 0
}
'";;
'mars_message.Coder')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"coderL\": 0,
    \"coderR\": 0,
    \"coderLPerSec\": 0,
    \"coderRPerSec\": 0
}
'";;
'mars_message.ColorRGBA')
COMPREPLY="'
{
    \"r\": 0.0,
    \"g\": 0.0,
    \"b\": 0.0,
    \"a\": 0.0
}
'";;
'mars_message.Debug')
COMPREPLY="'
{
    \"cmd\": \"\"
}
'";;
'mars_message.DevicePower')
COMPREPLY="'
{
    \"deviceName\": \"\",
    \"power\": 0
}
'";;
'mars_message.DoorInfo')
COMPREPLY="'
{
    \"_1\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    },
    \"_2\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    },
    \"minId\": 0,
    \"maxId\": 0
}
'";;
'mars_message.Event')
COMPREPLY="'
{
    \"event\": 0,
    \"param\": 0
}
'";;
'mars_message.FactoryTestConfig')
COMPREPLY="'
{
    \"gtSpeedMinLimit\": 0,
    \"batteryVolMaxLimit\": 0,
    \"batteryVolMinLimit\": 0,
    \"batteryCurrentMaxLimit\": 0,
    \"batteryCurrentMinLimit\": 0,
    \"waterBumpMinLimit\": 0,
    \"airBumpMinLimit\": 0
}
'";;
'mars_message.FusionPose')
COMPREPLY="'
{
    \"timetickMs\": 0,
    \"pose\": {
        \"pose\": {
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        },
        \"orientation\": {
            \"w\": 0.0,
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        }
    },
    \"rawYaw\": 0.0
}
'";;
'mars_message.GridMap')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"mapLoadTime\": 0,
    \"resolution\": 0.0,
    \"width\": 0,
    \"height\": 0,
    \"origin\": {
        \"pose\": {
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        },
        \"orientation\": {
            \"w\": 0.0,
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        }
    },
    \"pointCount\": 0,
    \"data\": []
}
'";;
'mars_message.IO')
COMPREPLY="'
{
    \"ioWaterTank\": 0,
    \"ioCleanWaterFull\": 0,
    \"ioCleanWaterEmpty\": 0,
    \"ioDusbox\": 0,
    \"ioSewageFull\": 0,
    \"ioLiftFinish\": 0
}
'";;
'mars_message.Imu')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"orientation\": {
        \"w\": 0.0,
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    },
    \"orientationCovariance\": [
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0
    ],
    \"angularVelocity\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    },
    \"angularVelocityCovariance\": [
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0
    ],
    \"linearAcceleraion\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    },
    \"linearAcceleraionCovariance\": [
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0
    ]
}
'";;
'mars_message.IrCode')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"count\": 0,
    \"code\": []
}
'";;
'mars_message.IrCode2')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"code0\": 0,
    \"code1\": 0,
    \"code2\": 0,
    \"code3\": 0
}
'";;
'mars_message.LaserScan')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"angleMin\": 0.0,
    \"angleMax\": 0.0,
    \"angleIncrement\": 0.0,
    \"timeIncrement\": 0.0,
    \"scanTime\": 0.0,
    \"rangeMin\": 0.0,
    \"rangeMax\": 0.0,
    \"count\": 0,
    \"ranges\": [],
    \"intensities\": []
}
'";;
'mars_message.MacAddrCode')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"code0\": 0,
    \"code1\": 0,
    \"code2\": 0,
    \"code3\": 0,
    \"code4\": 0,
    \"code5\": 0
}
'";;
'mars_message.MapRect')
COMPREPLY="'
{
    \"validNum\": 0,
    \"w\": 0.0,
    \"h\": 0.0,
    \"origin\": {
        \"pose\": {
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        },
        \"orientation\": {
            \"w\": 0.0,
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        }
    }
}
'";;
'mars_message.Marker')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"ns\": \"\",
    \"id\": 0,
    \"type\": 0,
    \"action\": 0,
    \"pose\": {
        \"pose\": {
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        },
        \"orientation\": {
            \"w\": 0.0,
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        }
    },
    \"scale\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    },
    \"color\": {
        \"r\": 0.0,
        \"g\": 0.0,
        \"b\": 0.0,
        \"a\": 0.0
    },
    \"lifetime\": 0,
    \"frame_locked\": 0,
    \"pointCount\": 0,
    \"points\": [],
    \"colors\": [],
    \"text\": \"\",
    \"mesh_resource\": \"\",
    \"mesh_use_embeded_materials\": 0
}
'";;
'mars_message.ObsAvoidance')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"count\": 0,
    \"angles\": [],
    \"ranges\": []
}
'";;
'mars_message.Odometry')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"pose\": {
        \"pose\": {
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        },
        \"orientation\": {
            \"w\": 0.0,
            \"x\": 0.0,
            \"y\": 0.0,
            \"z\": 0.0
        }
    },
    \"linearVelocity\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    },
    \"angularVelocity\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    }
}
'";;
'mars_message.OverloadConfig')
COMPREPLY="'
{
    \"wheel\": 0,
    \"sideBrush\": 0,
    \"mainBrush\": 0,
    \"rollBrush\": 0,
    \"liftMotor\": 0,
    \"waterPump\": 0,
    \"sewagePump\": 0,
    \"airPump\": 0,
    \"fanPump\": 0
}
'";;
'mars_message.PartsLifeConfig')
COMPREPLY="'
{
    \"sideBrushLife\": 0,
    \"sideBrushLifeMax\": 0,
    \"mainBrushLife\": 0,
    \"mainBrushLifeMax\": 0,
    \"rollBrushLife\": 0,
    \"rollBrushLifeMax\": 0,
    \"hiparLife\": 0,
    \"hiparLifeMax\": 0,
    \"ragLife\": 0,
    \"ragLifeMax\": 0
}
'";;
'mars_message.Path')
COMPREPLY="'
{
    \"count\": 0,
    \"points\": []
}
'";;
'mars_message.Point')
COMPREPLY="'
{
    \"x\": 0.0,
    \"y\": 0.0,
    \"z\": 0.0
}
'";;
'mars_message.PointCloud')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"count\": 0,
    \"points\": [],
    \"intensities\": []
}
'";;
'mars_message.PointCloud2')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"scanTime\": 0.0,
    \"count\": 0,
    \"points\": [],
    \"intensities\": []
}
'";;
'mars_message.Polygon')
COMPREPLY="'
{
    \"count\": 0,
    \"vetex\": []
}
'";;
'mars_message.Pose')
COMPREPLY="'
{
    \"pose\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    },
    \"orientation\": {
        \"w\": 0.0,
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    }
}
'";;
'mars_message.Quaternion')
COMPREPLY="'
{
    \"w\": 0.0,
    \"x\": 0.0,
    \"y\": 0.0,
    \"z\": 0.0
}
'";;
'mars_message.Range')
COMPREPLY="'
{
    \"rangeMM\": 0
}
'";;
'mars_message.Ranges')
COMPREPLY="'
{
    \"count\": 0,
    \"rangeMM\": []
}
'";;
'mars_message.RobotStatus')
COMPREPLY="'
{
    \"battLevel\": 0,
    \"battStatus\": 0,
    \"error\": 0,
    \"carpet\": 0
}
'";;
'mars_message.RoomInfo')
COMPREPLY="'
{
    \"roomMap\": {
        \"timestampMs\": 0,
        \"mapLoadTime\": 0,
        \"resolution\": 0.0,
        \"width\": 0,
        \"height\": 0,
        \"origin\": {
            \"pose\": {
                \"x\": 0.0,
                \"y\": 0.0,
                \"z\": 0.0
            },
            \"orientation\": {
                \"w\": 0.0,
                \"x\": 0.0,
                \"y\": 0.0,
                \"z\": 0.0
            }
        },
        \"pointCount\": 0,
        \"data\": []
    },
    \"doorCount\": 0,
    \"doors\": [],
    \"roomNum\": 0,
    \"roomPropeties\": [],
    \"cleanOrder\": []
}
'";;
'mars_message.RoomPropety')
COMPREPLY="'
{
    \"roomNo\": 0,
    \"roomArea\": {
        \"validNum\": 0,
        \"w\": 0.0,
        \"h\": 0.0,
        \"origin\": {
            \"pose\": {
                \"x\": 0.0,
                \"y\": 0.0,
                \"z\": 0.0
            },
            \"orientation\": {
                \"w\": 0.0,
                \"x\": 0.0,
                \"y\": 0.0,
                \"z\": 0.0
            }
        }
    },
    \"roomName\": \"\",
    \"cleanOrder\": 0,
    \"cleanRepeat\": 0,
    \"mopRepeat\": 0,
    \"colorOrder\": 0,
    \"donotSweep\": 0,
    \"donotMop\": 0,
    \"fanPower\": 0,
    \"waterLevel\": 0,
    \"enableYMop\": 0
}
'";;
'mars_message.Segment')
COMPREPLY="'
{
    \"begin\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    },
    \"end\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    }
}
'";;
'mars_message.Shell')
COMPREPLY="'
{
    \"count\": 0,
    \"code\": []
}
'";;
'mars_message.Speed')
COMPREPLY="'
{
    \"linear\": 0.0,
    \"angular\": 0.0
}
'";;
'mars_message.SweeperStatus')
COMPREPLY="'
{
    \"mcuStatus\": {
        \"battLevel\": 0,
        \"battStatus\": 0,
        \"error\": 0,
        \"carpet\": 0
    },
    \"runningState\": 0,
    \"pauseStatus\": 0,
    \"chargeStatus\": 0,
    \"cleanMode\": 0,
    \"cleanStatus\": 0,
    \"cleanTime\": 0,
    \"cleanArea\": 0.0,
    \"suctionPower\": 0,
    \"cistern\": 0,
    \"wipe\": 0,
    \"manualDirection\": 0,
    \"edgeBrushLife\": 0,
    \"rollBrushLife\": 0,
    \"filterLife\": 0,
    \"ragLife\": 0,
    \"donotDisturb\": 0,
    \"volume\": 0,
    \"cleanAreaTotal\": 0,
    \"cleanCountTotal\": 0,
    \"cleanTimeTotal\": 0,
    \"language\": 0,
    \"dustCollectionNum\": 0,
    \"dustCollectionSwitch\": 0,
    \"mapState\": 0,
    \"esimateArea\": 0,
    \"carpetCleanPefer\": 0,
    \"autoBoost\": 0,
    \"childLock\": 0,
    \"yMop\": 0
}
'";;
'mars_message.TimedTaskInfo')
COMPREPLY="'
{
    \"valid\": 0,
    \"weekDayMask\": 0,
    \"time\": 0,
    \"mapId\": 0,
    \"roomN\": 0,
    \"roomId\": [],
    \"zoomN\": 0,
    \"zoodId\": [],
    \"cleanMode\": 0,
    \"fan\": 0,
    \"water\": 0,
    \"cleanRepeat\": 0
}
'";;
'mars_message.Twist')
COMPREPLY="'
{
    \"timestampMs\": 0,
    \"linearVelocity\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    },
    \"angularVelocity\": {
        \"x\": 0.0,
        \"y\": 0.0,
        \"z\": 0.0
    }
}
'";;
'mars_message.Vector3')
COMPREPLY="'
{
    \"x\": 0.0,
    \"y\": 0.0,
    \"z\": 0.0
}
'";;
  
    esac
    fi
    return 0  
}  
complete -F _lcmd lcmd

