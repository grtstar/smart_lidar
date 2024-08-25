killall -9 lcm-tunnel
if [ x"$1" != x ]; then
    echo "#!/bin/bash" > ./src/lcm_tunnel/launch/scripts/lcm_tunnel.sh
    echo "lcm-tunnel -r \"SCAN|OBS|DOORS|IMU|ODOM|MAP|PATH|AROUND|Marker|RECT|BLOCK|path|REFINE|CLEAN|LOCAL\" $1" >> ./src/lcm_tunnel/launch/scripts/lcm_tunnel.sh
fi
roslaunch lidarcar_description robot.launch
