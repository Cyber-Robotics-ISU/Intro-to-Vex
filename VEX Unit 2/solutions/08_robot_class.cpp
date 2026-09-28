/* ============================================================
   08_robot_class.cpp    C++      SOLUTION  (8 of 8, capstone)
   ------------------------------------------------------------
   *** SOLUTION FILE - all bugs fixed. ***

   Compile:  g++ -Wall 08_robot_class.cpp -o 08_robot_class
   Run:      ./08_robot_class
   ============================================================ */

#include <iostream>

class Intake {
  private:
    int port;
    int currentSpeed;

  public:
    /* Constructor: runs when an Intake object is created. */
    Intake(int p) {
        port = p;
        currentSpeed = 0;        /* fix 3: give currentSpeed a known starting value */
    }

    void spin(int speed) { currentSpeed = speed; }
    int  getSpeed()      { return currentSpeed; }
    int  getPort()       { return port; }
};                               /* fix 1: a class definition ends with ; */

int main() {

    /* --- A: create an intake on port 8 -------------------- */
    Intake intake(8);
    std::cout << "intake port: " << intake.getPort() << std::endl;   /* fix 2: use the getter */
    std::cout << "intake speed at startup: " << intake.getSpeed() << std::endl;

    /* --- B: toggle the clamp twice; it should end open ---- */
    bool clampClosed = false;
    for (int i = 0; i < 2; i++) {        /* fix 4: < 2 toggles exactly twice */
        clampClosed = !clampClosed;
    }
    if (clampClosed) {                   /* fix 5: read the value, do not assign to it */
        std::cout << "clamp is closed" << std::endl;
    } else {
        std::cout << "clamp is open" << std::endl;
    }

    /* --- C: average of four motor temperatures ------------ */
    int total = 40 + 45 + 50 + 55;
    double average = total / 4.0;         /* fix 6: 4.0 keeps the .5 */
    std::cout << "average temp: " << average << std::endl;

    return 0;
}
