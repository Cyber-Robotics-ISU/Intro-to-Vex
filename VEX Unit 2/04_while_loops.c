/* ============================================================
   04_while_loops.c      C        DIFFICULTY: 4 of 8
   ------------------------------------------------------------
   Topics: while, do-while, continue, break, and == versus =.

   THERE ARE 5 BUGS IN THIS FILE.
   Two of them make the program hang forever. If it never
   finishes, that is the bug talking to you: press Ctrl+C.

   Compile:  gcc -Wall 04_while_loops.c -o 04_while_loops
   Run:      ./04_while_loops

   EXPECTED CORRECT OUTPUT:
     counting: 0 1 2 3 4
     attempt 1
     attempt 2
     attempt 3
     lift at 900
     lift at 800
     lift at 700
     lift at 600
     checking port 3
     checking port 4
     checking port 6
     loop 1 done
     loop 2 done
     loop 3 done
     stopped after 4 loops
   ============================================================ */

#include <stdio.h>

int main(void) {

    /* --- A: count 0 to 4 with a while loop ---------------- */
    int count = 0;
    printf("counting: ");
    while (count < 5) {
        printf("%d ", count);
    }
    printf("\n");

    /* --- B: try up to 3 times with a do-while ------------- */
    int attempts = 0;
    do {
        attempts++;
        printf("attempt %d\n", attempts);
    } while (attempts < 3)

    /* --- C: lower the lift and report each new height ------ */
    int height = 1000;
    while (height > 600) {
        printf("lift at %d\n", height);
        height = height - 100;
    }

    /* --- D: check ports 3 to 6, but skip port 5 ----------- */
    int port = 3;
    while (port <= 6) {
        if (port == 5) {
            continue;
        }
        printf("checking port %d\n", port);
        port++;
    }

    /* --- E: stop after 4 loops ---------------------------- */
    int loops = 0;
    while (loops < 10) {
        loops++;
        if (loops = 4) {
            break;
        }
        printf("loop %d done\n", loops);
    }
    printf("stopped after %d loops\n", loops);

    return 0;
}
