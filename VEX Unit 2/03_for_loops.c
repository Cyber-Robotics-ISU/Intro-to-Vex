/* ============================================================
   03_for_loops.c        C        DIFFICULTY: 3 of 8
   ------------------------------------------------------------
   Topics: for loops, array indexing, the off-by-one error,
           initialising an accumulator, the stray semicolon.

   THERE ARE 5 BUGS IN THIS FILE.
   One of them makes the program hang forever. If it never
   finishes, that is the bug talking to you: press Ctrl+C.

   Compile:  gcc -Wall 03_for_loops.c -o 03_for_loops
   Run:      ./03_for_loops

   EXPECTED CORRECT OUTPUT:
     countdown: 5 4 3 2 1
     motor 0: 40 C
     motor 1: 52 C
     motor 2: 47 C
     motor 3: 58 C
     motors over 55C: 1
     total of all temps: 197
     checking port 1
     checking port 3
     checking port 5
     checking port 7
   ============================================================ */

#include <stdio.h>

#define MOTOR_COUNT 4

int main(void) {

    /* --- A: count down from 5 to 1 ------------------------- */
    printf("countdown: ");
    for (int i = 5; i > 0; i++) {
        printf("%d ", i);
    }
    printf("\n");

    /* --- B: print every motor temperature ----------------- */
    int temps[MOTOR_COUNT] = {40, 52, 47, 58};
    for (int i = 0; i <= MOTOR_COUNT; i++) {
        printf("motor %d: %d C\n", i, temps[i]);
    }

    /* --- C: how many motors are over 55 C? ---------------- */
    int hotCount = 0;
    for (int i = 0; i < MOTOR_COUNT; i++) {
        if (temps[i] > 45) {
            hotCount++;
        }
    }
    printf("motors over 55C: %d\n", hotCount);

    /* --- D: add up all the temperatures ------------------- */
    int total;
    for (int i = 0; i < MOTOR_COUNT; i++) {
        total = total + temps[i];
    }
    printf("total of all temps: %d\n", total);

    /* --- E: step through the odd-numbered ports ----------- */
    for (int i = 1; i < 8; i += 2);
    {
        printf("checking port %d\n", i);
    }

    return 0;
}
