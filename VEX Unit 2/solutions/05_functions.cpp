/* ============================================================
   05_functions.cpp      C++      SOLUTION  (5 of 8)
   ------------------------------------------------------------
   *** SOLUTION FILE - all bugs fixed. ***

   Compile:  g++ -Wall 05_functions.cpp -o 05_functions
   Run:      ./05_functions
   ============================================================ */

#include <iostream>

const double WHEEL_DIAMETER = 3.25;   // inches

/* fix 1: prototypes tell main these functions exist before it
   calls them. (The alternative is to move the definitions above
   main.) */
double circumference();
double turnsToDegrees(double motorTurns);
void   clampInPlace(int &value);
double average(int a, int b);

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
    return WHEEL_DIAMETER * 3.14159;          // fix 2: diameter * pi, not * 2 * pi
}

/* One full motor turn is 360 degrees. */
double turnsToDegrees(double motorTurns) {
    return motorTurns * 360.0;                // fix 3: actually return the value
}

/* Clamp the caller's value into the legal motor range. */
void clampInPlace(int &value) {               // fix 4: & so we change the caller's variable
    if (value >  127) { value =  127; }
    if (value < -127) { value = -127; }
}

/* The average of two whole readings, as a decimal. */
double average(int a, int b) {
    return (a + b) / 2.0;                      // fix 5: 2.0 keeps the .5
}
