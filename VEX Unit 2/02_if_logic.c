/* ============================================================
   02_if_logic.c         C        DIFFICULTY: 2 of 8
   ------------------------------------------------------------
   Topics: bool and <stdbool.h>, if / else if / else,
           == versus =, logical operators, always use braces.

   THERE ARE 5 BUGS IN THIS FILE.
   Some stop it compiling. Some let it compile but do the
   wrong thing, which is the more dangerous kind.

   Compile:  gcc -Wall 02_if_logic.c -o 02_if_logic
   Run:      ./02_if_logic

   EXPECTED CORRECT OUTPUT:
     left motor too hot?  0
     right motor too hot? 1
     ring colour: red
     nothing in front of the sensor
     intake jammed - stopping
     check the intake before continuing
   ============================================================ */

#include <stdio.h>

/* Return true when the motor is over 55 C and must be stopped. */
bool motorTooHot(int temp) {
    if (temp = 55) {
        return true;
    }
    return false;
}

/* Report the ring colour, but only when something is actually
   in front of the optical sensor. */
void reportColour(int proximity, int hue) {
    if (proximity < 200) {
        printf("nothing in front of the sensor\n");
    }

    if (hue < 20 || > 340) {
        printf("ring colour: red\n");
    } else {
        printf("ring colour: not red\n");
    }
}

/* When the intake jams we must BOTH warn the driver and tell
   them to clear it. Both lines belong together. */
void safetyCheck(bool jammed) {
    if (jammed)
        printf("intake jammed - stopping\n");
        printf("check the intake before continuing\n");
}

int main(void) {

    /* --- A: is each motor too hot? -------------------------- */
    int leftTemp  = 48;
    int rightTemp = 60;
    printf("left motor too hot?  %d\n", motorTooHot(leftTemp));
    printf("right motor too hot? %d\n", motorTooHot(rightTemp));

    /* --- B: report the ring in front of the intake ---------- */
    reportColour(240, 12);   /* something there, red ring     */
    reportColour(150, 12);   /* nothing there: say so, no more */

    /* --- C: the intake safety guard ------------------------- */
    safetyCheck(false);      /* not jammed: print nothing      */
    safetyCheck(true);       /* jammed: print both lines       */

    return 0;
}
