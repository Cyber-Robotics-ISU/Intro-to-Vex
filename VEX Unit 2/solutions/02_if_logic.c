/* ============================================================
   02_if_logic.c         C        SOLUTION  (2 of 8)
   ------------------------------------------------------------
   *** SOLUTION FILE - all bugs fixed. ***

   Compile:  gcc -Wall 02_if_logic.c -o 02_if_logic
   Run:      ./02_if_logic
   ============================================================ */

#include <stdio.h>
#include <stdbool.h>          /* fix 1: C needs this for bool/true/false */

/* Return true when the motor is over 55 C and must be stopped. */
bool motorTooHot(int temp) {
    if (temp > 55) {          /* fix 2: compare with >, not assign with = */
        return true;
    }
    return false;
}

/* Report the ring colour, but only when something is actually
   in front of the optical sensor. */
void reportColour(int proximity, int hue) {
    if (proximity < 200) {
        printf("nothing in front of the sensor\n");
        return;              /* fix 4: stop here, do not fall through to a colour */
    }

    if (hue < 20 || hue > 340) {   /* fix 3: each side of || needs its own operand */
        printf("ring colour: red\n");
    } else {
        printf("ring colour: not red\n");
    }
}

/* When the intake jams we must BOTH warn the driver and tell
   them to clear it. Both lines belong together. */
void safetyCheck(bool jammed) {
    if (jammed) {            /* fix 5: braces keep both lines inside the if */
        printf("intake jammed - stopping\n");
        printf("check the intake before continuing\n");
    }
}

int main(void) {

    /* --- A: is each motor too hot? -------------------------- */
    int leftTemp  = 48;
    int rightTemp = 60;
    printf("left motor too hot?  %d\n", motorTooHot(leftTemp));
    printf("right motor too hot? %d\n", motorTooHot(rightTemp));

    /* --- B: report the ring in front of the intake ---------- */
    reportColour(240, 12);
    reportColour(150, 12);

    /* --- C: the intake safety guard ------------------------- */
    safetyCheck(false);
    safetyCheck(true);

    return 0;
}
