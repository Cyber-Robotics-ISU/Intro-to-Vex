/* ============================================================
   04_while_loops.c      C        SOLUTION  (4 of 8)
   ------------------------------------------------------------
   *** SOLUTION FILE - all bugs fixed. ***

   Compile:  gcc -Wall 04_while_loops.c -o 04_while_loops
   Run:      ./04_while_loops
   ============================================================ */

#include <stdio.h>

int main(void) {

    /* --- A: count 0 to 4 with a while loop ---------------- */
    int count = 0;
    printf("counting: ");
    while (count < 5) {
        printf("%d ", count);
        count++;                     /* fix 1: without this the loop never ends */
    }
    printf("\n");

    /* --- B: try up to 3 times with a do-while ------------- */
    int attempts = 0;
    do {
        attempts++;
        printf("attempt %d\n", attempts);
    } while (attempts < 3);          /* fix 2: a do-while ends in a semicolon */

    /* --- C: lower the lift and report each new height ------ */
    int height = 1000;
    while (height > 600) {
        height = height - 100;       /* fix 3: move first, then report the new height */
        printf("lift at %d\n", height);
    }

    /* --- D: check ports 3 to 6, but skip port 5 ----------- */
    int port = 3;
    while (port <= 6) {
        if (port == 5) {
            port++;                  /* fix 4: step past 5 before continue */
            continue;
        }
        printf("checking port %d\n", port);
        port++;
    }

    /* --- E: stop after 4 loops ---------------------------- */
    int loops = 0;
    while (loops < 10) {
        loops++;
        if (loops == 4) {            /* fix 5: == compares, = would assign */
            break;
        }
        printf("loop %d done\n", loops);
    }
    printf("stopped after %d loops\n", loops);

    return 0;
}
