/* ============================================================
   01_variables.c        C        DIFFICULTY: 1 of 8
   ------------------------------------------------------------
   Topics: int, double, initialisation, integer division,
           printf format specifiers, naming rules.

   THERE ARE 5 BUGS IN THIS FILE.
   Some stop it compiling. Some let it compile but print the
   wrong answer, which is the more dangerous kind.

   Compile:  gcc -Wall 01_variables.c -o 01_variables
   Run:      ./01_variables

   EXPECTED CORRECT OUTPUT:
     Motor port:      7
     Wheel diameter:  3.25 inches
     Total ticks:     1080
     Average ticks:   360.0
     Trip distance:   10.21 inches
     Second port:     8
   ============================================================ */

#include <stdio.h>

int main(void) {

    /* --- Section A: whole numbers --------------------------- */
    int motorPort = 7

    /* --- Section B: decimals -------------------------------- */
    double wheelDiameter = 3.25;

    /* --- Section C: three encoder readings ------------------ */
    int reading1 = 360;
    int reading2 = 360;
    int reading3 = 360;
    int totalTicks;

    totalTicks = totalTicks + reading1 + reading2 + reading3;

    /* We want the average as a decimal, e.g. 360.0 */
    double averageTicks = totalTicks / 3;

    /* --- Section D: how far does one wheel turn take us? ---- */
    /* circumference = diameter * pi */
    double tripDistance;
    tripDistance = wheelDiameter * 3.14159;

    /* --- Section E: a second motor -------------------------- */
    int 2ndMotorPort = 8;

    /* --- Print everything ----------------------------------- */
    printf("Motor port:      %d\n", motorPort);
    printf("Wheel diameter:  %d inches\n", wheelDiameter);
    printf("Total ticks:     %d\n", totalTicks);
    printf("Average ticks:   %.1f\n", averageTicks);
    printf("Trip distance:   %.2f inches\n", tripDistance);
    printf("Second port:     %d\n", 2ndMotorPort);

    return 0;
}
