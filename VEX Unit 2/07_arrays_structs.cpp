/* ============================================================
   07_arrays_structs.cpp   C++    DIFFICULTY: 7 of 8
   ------------------------------------------------------------
   Topics: C arrays and the sizeof trap, std::vector and its
           bounds, structs and the dot operator, enum class,
           and range-based for with a reference.

   THERE ARE 5 BUGS IN THIS FILE.
   Note this is a C++ file: compile it with g++, not gcc.

   Compile:  g++ -Wall 07_arrays_structs.cpp -o 07_arrays_structs
   Run:      ./07_arrays_structs

   EXPECTED CORRECT OUTPUT:
     port count: 4
     reading total: 54
     heading: 90
     lift ready to score
     first motor speed: 127
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

/* Count how many ports are in the array.
   Careful: inside a function an array argument is really a
   pointer, so sizeof measures the pointer, not the array. */
int countPorts(int ports[]) {
    return sizeof(ports) / sizeof(ports[0]);
}

int main() {

    /* --- A: how many drive ports are configured? ---------- */
    int ports[4] = {11, 12, 13, 14};
    std::cout << "port count: " << countPorts(ports) << std::endl;

    /* --- B: total of the sensor readings ------------------ */
    std::vector<double> readings = {12.0, 13.0, 14.0, 15.0};
    double total = 0;
    for (int i = 0; i <= readings.size(); i++) {
        total = total + readings[i];
    }
    std::cout << "reading total: " << total << std::endl;

    /* --- C: read the robot's heading ---------------------- */
    Pose robot = {0.0, 0.0, 90.0};
    std::cout << "heading: " << robot->heading << std::endl;

    /* --- D: is the lift ready to score? ------------------- */
    LiftState lift = LiftState::SCORE;
    if (lift == SCORE) {
        std::cout << "lift ready to score" << std::endl;
    }

    /* --- E: set every drive motor to full speed ----------- */
    std::vector<Motor> motors = {{11, 0}, {12, 0}, {13, 0}, {14, 0}};
    for (Motor m : motors) {
        m.speed = 127;
    }
    std::cout << "first motor speed: " << motors[0].speed << std::endl;

    return 0;
}
