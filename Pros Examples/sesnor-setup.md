---
layout: default
title: Device Setup
description: Motors, Motor Groups, Sensors, and Controllers
---

These examples use **PROS 4** (the kernel this template is built on). Put the definitions near the top of a `.cpp` file, outside of any function, so every function in that file can use them.

## Controllers

### Define the Controllers
```cpp
pros::Controller main_Controller(pros::E_CONTROLLER_MASTER);    // main driver
pros::Controller partner_Controller(pros::E_CONTROLLER_PARTNER); // second driver (optional)
```

### Reading Inputs
Joysticks return a value from -127 to 127. Buttons return `true` or `false`.
```cpp
int leftY  = main_Controller.get_analog(ANALOG_LEFT_Y);  // left stick up/down
int leftX  = main_Controller.get_analog(ANALOG_LEFT_X);  // left stick left/right
int rightY = main_Controller.get_analog(ANALOG_RIGHT_Y); // right stick up/down
int rightX = main_Controller.get_analog(ANALOG_RIGHT_X); // right stick left/right

bool isHeld    = main_Controller.get_digital(DIGITAL_R1);           // true the whole time it is held
bool isPressed = main_Controller.get_digital_new_press(DIGITAL_R1); // true only on the first loop it is pressed
```

### Button Names
| Group | Buttons |
|-------|---------|
| Bumpers | `DIGITAL_L1` `DIGITAL_L2` `DIGITAL_R1` `DIGITAL_R2` |
| Face | `DIGITAL_A` `DIGITAL_B` `DIGITAL_X` `DIGITAL_Y` |
| D-Pad | `DIGITAL_UP` `DIGITAL_DOWN` `DIGITAL_LEFT` `DIGITAL_RIGHT` |
| Sticks | `ANALOG_LEFT_X` `ANALOG_LEFT_Y` `ANALOG_RIGHT_X` `ANALOG_RIGHT_Y` |

### Screen and Rumble
The controller screen only updates about every 50ms, so don't print to it every loop.
```cpp
main_Controller.print(0, 0, "Battery: %d%%", (int)pros::battery::get_capacity()); // line 0, column 0
main_Controller.clear_line(1);  // clear line 1
main_Controller.rumble(".-");   // . = short, - = long, space = pause
```

## Motors

### Define a Motor
A negative port number reverses the motor.
```cpp
pros::Motor intakeMotor(14, pros::MotorGearset::green); // port 14, forward
pros::Motor liftMotor(-15, pros::MotorGearset::red);    // port 15, reversed
```

| Gearset | Cartridge Color | Max RPM |
|---------|-----------------|---------|
| `pros::MotorGearset::red`   | Red   | 100 |
| `pros::MotorGearset::green` | Green | 200 |
| `pros::MotorGearset::blue`  | Blue  | 600 |

### Moving a Motor
```cpp
intakeMotor.move(127);             // voltage-style power, -127 to 127
intakeMotor.move_velocity(200);    // target RPM (limited by the gearset)
intakeMotor.move_voltage(12000);   // millivolts, -12000 to 12000
intakeMotor.move_relative(360, 100); // spin 360 degrees from where it is now at 100 RPM
intakeMotor.move_absolute(0, 100);   // go to position 0 at 100 RPM
intakeMotor.brake();               // stop using the current brake mode
```

### Brake Modes
```cpp
intakeMotor.set_brake_mode(pros::MotorBrake::coast); // spins freely when stopped
intakeMotor.set_brake_mode(pros::MotorBrake::brake); // stops quickly
intakeMotor.set_brake_mode(pros::MotorBrake::hold);  // actively holds its position (good for lifts/arms)
```

### Reading Motor Info
```cpp
double position = intakeMotor.get_position();        // degrees by default
double velocity = intakeMotor.get_actual_velocity(); // RPM
double temp     = intakeMotor.get_temperature();     // Celsius, motors slow down around 55C
intakeMotor.tare_position();                         // reset position to 0
```

## Motor Groups

### Define a Motor Group
A motor group lets several motors act like one. Negative ports are reversed.
```cpp
pros::MotorGroup leftDrive({-1, -2, -3}, pros::MotorGearset::blue); // all reversed
pros::MotorGroup rightDrive({4, 5, 6}, pros::MotorGearset::blue);
pros::MotorGroup liftMotors({7, -8}, pros::MotorGearset::red);      // one reversed so they spin the same way
```

### Using a Motor Group
Motor groups use the same functions as a single motor.
```cpp
liftMotors.move(127);
liftMotors.set_brake_mode_all(pros::MotorBrake::hold);
liftMotors.tare_position_all();
double liftPos = liftMotors.get_position(); // position of the first motor in the group
```

## Sensors

### Inertial Sensor (IMU)
Calibrating takes about 2 seconds. Do it in `initialize()` and don't move the robot while it runs.
```cpp
pros::Imu imu(10);

void initialize() {
    imu.reset(true); // true = wait until calibration finishes
}

double heading  = imu.get_heading();  // 0 to 360
double rotation = imu.get_rotation(); // keeps counting past 360 (e.g. 450)
imu.tare_rotation();                  // reset rotation to 0
```

### Rotation Sensor
Values are in **centidegrees** (100 = 1 degree).
```cpp
pros::Rotation armRotation(11);  // use -11 to reverse it

double angle    = armRotation.get_angle() / 100.0;    // 0 to 360 degrees
double position = armRotation.get_position() / 100.0; // keeps counting past 360
armRotation.reset_position();                         // reset position to 0
```

### Distance Sensor
```cpp
pros::Distance frontDistance(12);

int mm = frontDistance.get_distance(); // millimeters to the nearest object
double inches = mm / 25.4;
```

### Optical Sensor
```cpp
pros::Optical colorSensor(13);

colorSensor.set_led_pwm(100);                  // turn the LED on to 100% (helps in dark areas)
double hue = colorSensor.get_hue();            // 0 to 360, red is near 0/360, blue is near 220
int proximity = colorSensor.get_proximity();   // 0 (far) to 255 (close)

bool seesRed  = (hue < 30 || hue > 330);
bool seesBlue = (hue > 180 && hue < 260);
```

### Pneumatics (Solenoid)
Three-wire ports use letters `'A'` to `'H'`.
```cpp
bool clampToggle = false; // clamp toggle variable
pros::adi::DigitalOut clampPiston('A');

void toggleClamp(){
    clampToggle = !clampToggle;
    clampPiston.set_value(clampToggle);
}
```

### Limit Switch / Bumper Switch
```cpp
pros::adi::DigitalIn liftLimit('B');

bool isPressed  = liftLimit.get_value();     // true while pressed
bool newPress   = liftLimit.get_new_press(); // true only on the first loop it is pressed
```

### Potentiometer
```cpp
pros::adi::Potentiometer armPot('C');

double armAngle = armPot.get_angle(); // degrees
```

## Main Function
Putting it all together. Always keep a `pros::delay` in the loop so the brain has time to do everything else.
```cpp
void opcontrol() {
  while(true){
    // hold R1 to run the intake
    if (main_Controller.get_digital(DIGITAL_R1)){
        intakeMotor.move(127);
    } else {
        intakeMotor.move(0);
    }

    // press A to toggle the clamp
    if (main_Controller.get_digital_new_press(DIGITAL_A)){
        toggleClamp();
    }

    // stop the lift when it hits the limit switch
    if (liftLimit.get_value()){
        liftMotors.move(0);
    }

    pros::delay(10); // don't hog the brain
  }
}
```
