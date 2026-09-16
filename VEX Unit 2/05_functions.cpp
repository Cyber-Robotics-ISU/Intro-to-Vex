/* ============================================================
   05_functions.cpp      C++      DIFFICULTY: 5 of 8
   ------------------------------------------------------------
   Topics: writing functions, declaring them before use,
           returning a value, passing by value versus by
           reference, and integer division inside a function.

   THERE ARE 5 BUGS IN THIS FILE.
   Note this is a C++ file: compile it with g++, not gcc.

   Compile:  g++ -Wall 05_functions.cpp -o 05_functions
   Run:      ./05_functions

   EXPECTED CORRECT OUTPUT:
     circumference: 10.2102 inches
     2.5 turns is 900 degrees
     clamped command: 127
     average reading: 113.5
   ============================================================ */

#include <iostream>

const double WHEEL_DIAMETER = 3.25;   // inches

int main() {

    /* --- A: the wheel's circumference --------------------- */
    std::cout << "circumference: " << circumference() << " inches" << std::endl;

    /* --- B: convert motor turns into degrees -------------- */
    std::cout << "2.5 turns is " << turnsToDegrees(2.5) << " degrees" << std::endl;

    /* --- C: clamp a motor command into [-127, 127] -------- */
    int command = 200;
    clampInPlace(command);
    std::cout << "clamped command: " << command << std::endl;

    /* --- D: average two sensor readings ------------------- */
    std::cout << "average reading: " << average(113, 114) << std::endl;

    return 0;
}

/* circumference = diameter * pi */
double circumference() {
    return WHEEL_DIAMETER * 2 * 3.14159;
}

/* One full motor turn is 360 degrees. */
double turnsToDegrees(double motorTurns) {
    motorTurns * 360.0;
}

/* Clamp the caller's value into the legal motor range. */
void clampInPlace(int value) {
    if (value >  127) { value =  127; }
    if (value < -127) { value = -127; }
}

/* The average of two whole readings, as a decimal. */
double average(int a, int b) {
    return (a + b) / 2;
}
