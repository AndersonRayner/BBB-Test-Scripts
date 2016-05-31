# A script for making a lot of stuff
# Run using
#
#     nohup ./make_all.sh &
#
clear
rm *.elf

BUILD_DIR="/root/sdcard/ardupilot/build/bbbmini"

# Build Example Scripts
cd sdcard/ardupilot
/root/sdcard/ardupilot/modules/waf/waf-light examples

# AP_Notify
cp $BUILD_DIR/examples/ToshibaLED_test /root/LED.elf

# Airspeed
cp $BUILD_DIR/examples/Airspeed /root/Airspeed.elf

# Baro
cp $BUILD_DIR/examples/BARO_generic /root/Baro.elf

# Compass
cp $BUILD_DIR/examples/AP_Compass_test /root/Compass.elf

# INS
cp $BUILD_DIR/examples/INS_generic /root/INS.elf

# RCInput
cp $BUILD_DIR/examples/RCInput /root/RCInput.elf

# RCOutput
cp $BUILD_DIR/examples/RCOutput /root/RCOutput.elf

# ArduCopter
/root/sdcard/ardupilot/modules/waf/waf-light copter
cp $BUILD_DIR/bin/arducopter /root/ArduCopter.elf
