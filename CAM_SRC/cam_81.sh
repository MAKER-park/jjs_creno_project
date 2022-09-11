#!/bin/sh

input=/usr/local/lib/mjpg-streamer/input_uvc.so
output=/usr/local/lib/mjpg-streamer/output_http.so
port=8081
device=/dev/video1
webroot=/usr/local/share/mjpg-streamer/www

mjpg_streamer -i "$input -d $device -r 640x480 -f 1" -o "$output -p $port -w $webroot"
