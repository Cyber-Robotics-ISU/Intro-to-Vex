/* ============================================================
   08_robot_class.cpp    C++      DIFFICULTY: 8 of 8  (capstone)
   ------------------------------------------------------------
   Topics: everything so far, wrapped in a class. Constructors,
           private versus public, calling methods, plus the
           integer-division and = versus == traps returning
           one last time.

   THERE ARE 6 BUGS IN THIS FILE.
   Note this is a C++ file: compile it with g++, not gcc.

   Compile:  g++ -Wall 08_robot_class.cpp -o 08_robot_class
   Run:      ./08_robot_class

   EXPECTED CORRECT OUTPUT:
     intake port: 8
     intake speed at startup: 0
     clamp is open
     average temp: 47.5
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
    }

    void spin(int speed) { currentSpeed = speed; }
    int  getSpeed()      { return currentSpeed; }
    int  getPort()       { return port; }
}

int main() {

    /* --- A: create an intake on port 8 -------------------- */
    Intake intake(8);
    std::cout << "intake port: " << intake.port << std::endl;
    std::cout << "intake speed at startup: " << intake.getSpeed() << std::endl;

    /* --- B: toggle the clamp twice; it should end open ---- */
    bool clampClosed = false;
    for (int i = 0; i <= 2; i++) {
        clampClosed = !clampClosed;
    }
    if (clampClosed = true) {
        std::cout << "clamp is closed" << std::endl;
    } else {
        std::cout << "clamp is open" << std::endl;
    }

    /* --- C: average of four motor temperatures ------------ */
    int total = 40 + 45 + 50 + 55;
    double average = total / 4;
    std::cout << "average temp: " << average << std::endl;

    return 0;
}
