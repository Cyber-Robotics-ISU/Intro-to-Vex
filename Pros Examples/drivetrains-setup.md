---
layout: default
title: Drivetrains
description: Tank, Arcade, Split Arcade, and Mecanum
---

These examples use **PROS 4** motor groups. Each one reads the joysticks (-127 to 127) and sends power to the drive with `move()`.

## Initial Setup

### Normal Drivetrain (Tank, Arcade, Split Arcade)
One motor group per side. Flip the sign of the ports if the robot drives backwards.
```cpp
pros::Controller main_Controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftDrive({-1, -2, -3}, pros::MotorGearset::blue);
pros::MotorGroup rightDrive({4, 5, 6}, pros::MotorGearset::blue);
```

### Deadband Helper
Joysticks rarely rest at exactly 0, so this ignores tiny values to stop the robot from creeping.
```cpp
int deadband(int value, int range = 5){
    if (abs(value) < range) return 0;
    return value;
}
```

## Tank Drive
Left stick controls the left side, right stick controls the right side.
```cpp
void tankDrive(){
    int left  = deadband(main_Controller.get_analog(ANALOG_LEFT_Y));
    int right = deadband(main_Controller.get_analog(ANALOG_RIGHT_Y));

    leftDrive.move(left);
    rightDrive.move(right);
}
```

## Arcade Drive (Single Stick)
One stick does everything. Up/down drives forward and backward, left/right turns.
```cpp
void arcadeDrive(){
    int forward = deadband(main_Controller.get_analog(ANALOG_LEFT_Y));
    int turn    = deadband(main_Controller.get_analog(ANALOG_LEFT_X));

    leftDrive.move(forward + turn);
    rightDrive.move(forward - turn);
}
```

## Split Arcade Drive
Left stick drives forward and backward, right stick turns. This is the most common choice for drivers.
```cpp
void splitArcadeDrive(){
    int forward = deadband(main_Controller.get_analog(ANALOG_LEFT_Y));
    int turn    = deadband(main_Controller.get_analog(ANALOG_RIGHT_X));

    leftDrive.move(forward + turn);
    rightDrive.move(forward - turn);
}
```

### Slower Turning (Optional)
Multiply the turn value to make turning less twitchy.
```cpp
double turnScale = 0.7; // 70% turn speed
int turn = deadband(main_Controller.get_analog(ANALOG_RIGHT_X)) * turnScale;
```

## Mecanum Drive
Mecanum wheels can drive forward, strafe sideways, and turn at the same time. The same code also works for an **X-Drive**.

### Define the Motors
Each wheel needs its own motor (or motor group). The rollers on the wheels should make an **X** shape when looking down at the robot.
```cpp
pros::Motor frontLeft(-1, pros::MotorGearset::green);
pros::Motor backLeft(-2, pros::MotorGearset::green);
pros::Motor frontRight(3, pros::MotorGearset::green);
pros::Motor backRight(4, pros::MotorGearset::green);
```

### Mecanum Function
Left stick drives and strafes, right stick turns.
```cpp
void mecanumDrive(){
    int forward = deadband(main_Controller.get_analog(ANALOG_LEFT_Y));  // forward/back
    int strafe  = deadband(main_Controller.get_analog(ANALOG_LEFT_X));  // left/right
    int turn    = deadband(main_Controller.get_analog(ANALOG_RIGHT_X)); // rotate

    int fl = forward + strafe + turn;
    int bl = forward - strafe + turn;
    int fr = forward - strafe - turn;
    int br = forward + strafe - turn;

    // if any wheel is over 127, scale them all down so the robot keeps moving in the right direction
    int maxPower = std::max({abs(fl), abs(bl), abs(fr), abs(br), 127});
    fl = fl * 127 / maxPower;
    bl = bl * 127 / maxPower;
    fr = fr * 127 / maxPower;
    br = br * 127 / maxPower;

    frontLeft.move(fl);
    backLeft.move(bl);
    frontRight.move(fr);
    backRight.move(br);
}
```

### Field-Centric Mecanum (Optional)
With an IMU the robot strafes relative to the **field** instead of itself, so pushing the stick up always moves away from the driver no matter which way the robot is facing.
```cpp
pros::Imu imu(10); // calibrate with imu.reset(true) in initialize()

void fieldCentricMecanum(){
    int forward = deadband(main_Controller.get_analog(ANALOG_LEFT_Y));
    int strafe  = deadband(main_Controller.get_analog(ANALOG_LEFT_X));
    int turn    = deadband(main_Controller.get_analog(ANALOG_RIGHT_X));

    // rotate the joystick input by the robot's heading
    double heading = imu.get_heading() * M_PI / 180.0; // degrees to radians
    double rotForward = forward * cos(heading) + strafe * sin(heading);
    double rotStrafe  = -forward * sin(heading) + strafe * cos(heading);

    double fl = rotForward + rotStrafe + turn;
    double bl = rotForward - rotStrafe + turn;
    double fr = rotForward - rotStrafe - turn;
    double br = rotForward + rotStrafe - turn;

    double maxPower = std::max({fabs(fl), fabs(bl), fabs(fr), fabs(br), 127.0});
    frontLeft.move(fl * 127 / maxPower);
    backLeft.move(bl * 127 / maxPower);
    frontRight.move(fr * 127 / maxPower);
    backRight.move(br * 127 / maxPower);
}
```

## Main Function
Pick one drive style and call it every loop.
```cpp
void opcontrol() {
  // coast feels smoother for driving, hold/brake makes it harder to get pushed
  leftDrive.set_brake_mode_all(pros::MotorBrake::coast);
  rightDrive.set_brake_mode_all(pros::MotorBrake::coast);

  while(true){
    splitArcadeDrive();  // or tankDrive(), arcadeDrive(), mecanumDrive()

    pros::delay(10); // don't hog the brain
  }
}
```

### Switching Drive Styles With a Button
This lets the driver swap between tank and split arcade by pressing the Y button.
```cpp
bool useTank = false; // drive style toggle variable

void opcontrol() {
  while(true){
    if (main_Controller.get_digital_new_press(DIGITAL_Y)){
      useTank = !useTank;
      main_Controller.rumble(".");
    }

    if (useTank){
      tankDrive();
    } else {
      splitArcadeDrive();
    }

    pros::delay(10);
  }
}
```
