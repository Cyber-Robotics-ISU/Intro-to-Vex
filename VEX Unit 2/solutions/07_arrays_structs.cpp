/* ============================================================
   07_arrays_structs.cpp   C++    SOLUTION  (7 of 8)
   ------------------------------------------------------------
   *** SOLUTION FILE - all bugs fixed. ***

   Compile:  g++ -Wall 07_arrays_structs.cpp -o 07_arrays_structs
   Run:      ./07_arrays_structs
   ============================================================ */

#include <iostream>
#include <vector>

/* A stand-in for a motor: a port and a target speed. */
struct Motor {
    int port;
    int speed;
};

/* The robot's position and facing on the field. */
struct Pose {
    double x;          // inches
    double y;          // inches
    double heading;    // degrees
};

enum class LiftState { DOWN, LOAD, SCORE };

/* fix 1: an array decays to a pointer inside a function, so the
   caller must tell us how long it is. */
int countPorts(int ports[], int length) {
    return length;
}

int main() {

    /* --- A: how many drive ports are configured? ---------- */
    int ports[4] = {11, 12, 13, 14};
    std::cout << "port count: " << countPorts(ports, 4) << std::endl;

    /* --- B: total of the sensor readings ------------------ */
    std::vector<double> readings = {12.0, 13.0, 14.0, 15.0};
    double total = 0;
    for (size_t i = 0; i < readings.size(); i++) {   /* fix 2: size_t and < */
        total = total + readings[i];
    }
    std::cout << "reading total: " << total << std::endl;

    /* --- C: read the robot's heading ---------------------- */
    Pose robot = {0.0, 0.0, 90.0};
    std::cout << "heading: " << robot.heading << std::endl;   /* fix 3: . not -> */

    /* --- D: is the lift ready to score? ------------------- */
    LiftState lift = LiftState::SCORE;
    if (lift == LiftState::SCORE) {          /* fix 4: qualify the enum name */
        std::cout << "lift ready to score" << std::endl;
    }

    /* --- E: set every drive motor to full speed ----------- */
    std::vector<Motor> motors = {{11, 0}, {12, 0}, {13, 0}, {14, 0}};
    for (Motor &m : motors) {                /* fix 5: & so we change the real motors */
        m.speed = 127;
    }
    std::cout << "first motor speed: " << motors[0].speed << std::endl;

    return 0;
}
