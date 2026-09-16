/* ============================================================
   03_for_loops.c        C        SOLUTION  (3 of 8)
   ------------------------------------------------------------
   *** SOLUTION FILE - all bugs fixed. ***

   Compile:  gcc -Wall 03_for_loops.c -o 03_for_loops
   Run:      ./03_for_loops
   ============================================================ */

#include <stdio.h>

#define MOTOR_COUNT 4

int main(void) {

    /* --- A: count down from 5 to 1 ------------------------- */
    printf("countdown: ");
    for (int i = 5; i > 0; i--) {          /* fix 1: i-- so the loop ends */
        printf("%d ", i);
    }
    printf("\n");

    /* --- B: print every motor temperature ----------------- */
    int temps[MOTOR_COUNT] = {40, 52, 47, 58};
    for (int i = 0; i < MOTOR_COUNT; i++) {  /* fix 2: < stops before temps[4] */
        printf("motor %d: %d C\n", i, temps[i]);
    }

    /* --- C: how many motors are over 55 C? ---------------- */
    int hotCount = 0;
    for (int i = 0; i < MOTOR_COUNT; i++) {
        if (temps[i] > 55) {               /* fix 3: 55, not 45 */
            hotCount++;
        }
    }
    printf("motors over 55C: %d\n", hotCount);

    /* --- D: add up all the temperatures ------------------- */
    int total = 0;                          /* fix 4: start the accumulator at 0 */
    for (int i = 0; i < MOTOR_COUNT; i++) {
        total = total + temps[i];
    }
    printf("total of all temps: %d\n", total);

    /* --- E: step through the odd-numbered ports ----------- */
    for (int i = 1; i < 8; i += 2) {        /* fix 5: no stray ; after the for */
        printf("checking port %d\n", i);
    }

    return 0;
}
