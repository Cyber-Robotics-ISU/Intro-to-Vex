/* ============================================================
   01_variables.c        C        SOLUTION  (1 of 8)
   ------------------------------------------------------------
   *** SOLUTION FILE - all bugs fixed. ***
   Compare against your own fix; there is often more than one
   correct way to write it.

   Compile:  gcc -Wall 01_variables.c -o 01_variables
   Run:      ./01_variables
   ============================================================ */

#include <stdio.h>

int main(void) {

    /* --- Section A: whole numbers --------------------------- */
    int motorPort = 7;                       /* fix 1: semicolon */

    /* --- Section B: decimals -------------------------------- */
    double wheelDiameter = 3.25;

    /* --- Section C: three encoder readings ------------------ */
    int reading1 = 360;
    int reading2 = 360;
    int reading3 = 360;
    int totalTicks;

    totalTicks = reading1 + reading2 + reading3;   /* fix 2: don't read totalTicks first */

    /* We want the average as a decimal, e.g. 360.0 */
    double averageTicks = totalTicks / 3.0;        /* fix 3: 3.0 keeps the decimal */

    /* --- Section D: how far does one wheel turn take us? ---- */
    double tripDistance;
    tripDistance = wheelDiameter * 3.14159;

    /* --- Section E: a second motor -------------------------- */
    int secondMotorPort = 8;                 /* fix 5: names cannot start with a digit */

    /* --- Print everything ----------------------------------- */
    printf("Motor port:      %d\n", motorPort);
    printf("Wheel diameter:  %.2f inches\n", wheelDiameter);   /* fix 4: %f for a double */
    printf("Total ticks:     %d\n", totalTicks);
    printf("Average ticks:   %.1f\n", averageTicks);
    printf("Trip distance:   %.2f inches\n", tripDistance);
    printf("Second port:     %d\n", secondMotorPort);

    return 0;
}
