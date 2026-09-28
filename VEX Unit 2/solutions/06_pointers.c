/* ============================================================
   06_pointers.c         C        SOLUTION  (6 of 8)
   ------------------------------------------------------------
   *** SOLUTION FILE - all bugs fixed. ***

   Compile:  gcc -Wall 06_pointers.c -o 06_pointers
   Run:      ./06_pointers
   ============================================================ */

#include <stdio.h>

/* Swap the two values the caller gave us. */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Wrap a heading into the range 0 to 359, in place. */
void wrapHeading(int *heading) {
    while (*heading >= 360) {          /* fix 1: compare the value, not the pointer */
        *heading = *heading - 360;
    }
}

int main(void) {

    /* --- A: a pointer to an int ----------------------------- */
    int score = 12;
    int *p = &score;                   /* fix 2: a pointer holds an address */

    printf("score starts at %d\n", score);
    printf("read through the pointer: %d\n", *p);   /* fix 3: * reads the value */

    /* --- B: write through the pointer ----------------------- */
    *p = 20;                           /* fix 4: * writes into score itself */
    printf("after writing through the pointer: %d\n", score);

    /* --- C: swap two values using pointers ------------------ */
    int left  = 100;
    int right = 50;
    printf("before swap: left %d, right %d\n", left, right);
    swap(&left, &right);               /* fix 5: pass addresses so swap can change them */
    printf("after swap:  left %d, right %d\n", left, right);

    /* --- D: wrap a couple of headings ----------------------- */
    int heading1 = 350;
    wrapHeading(&heading1);
    printf("heading was 350, wrapped to %d\n", heading1);

    int heading2 = 400;
    wrapHeading(&heading2);
    printf("heading was 400, wrapped to %d\n", heading2);

    /* --- E: a pointer must point somewhere real ------------- */
    int realTarget = 0;
    int *safePointer = &realTarget;    /* fix 6: point it at a real variable first */
    *safePointer = 99;

    return 0;
}
