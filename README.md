# car-steering-wheel-control-switch-keyboard

After upgrading the car head unit to a selfmade RaspberryPI 4 with Android https://konstakang.com/devices/rpi4/AOSP12/ onboard, the question arose: "what to do with steering wheel control switch".
So, it can be easily upgraded to a Bluetooth keyboard which just connects to the head unit wirelessly.
![image](https://github.com/usatenko/car-steering-wheel-control-switch-keyboard/assets/1710344/754fe04e-78db-49d1-b514-91ca1a498978)

As the board for Keyboard I used XIAO ESP32 C3.
Pinout:
![image](https://github.com/usatenko/car-steering-wheel-control-switch-keyboard/assets/1710344/e59508d7-a8f8-4d87-8ddb-68d651c60d5f)
- Put 200R resistor between ESP32 GND and ESP32 GPIO2
- Connect pin 1 from Steering Control Switch (SCS) to ESP32 3.3V
- Connect pin 2 from SCS to ESP32 GPIO2

Upload the code to ESP32 and that's it.

You may need to adopt values that represent button values on line 18, because resistance of the cables that connect ESP32 and SCS - differ, so you may have different values, just check Serial Monitor for the real values in Arduino IDE.

On the head unit connect the Bluetooth "Ford Wheel Keys" and map the keyboard keys to specific actions.
