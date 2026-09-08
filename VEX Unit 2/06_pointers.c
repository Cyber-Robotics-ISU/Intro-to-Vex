/* ============================================================
   06_pointers.c         C        DIFFICULTY: 5 of 8
   ------------------------------------------------------------
   Topics: addresses, the & operator, the * operator,
           dereferencing, passing pointers to functions,
           uninitialised pointers.

   THERE ARE 6 BUGS IN THIS FILE.

   WARNING: one of these bugs may crash the program with a
   segmentation fault. That is the bug talking to you.

   Compile:  gcc -Wall 06_pointers.c -o 06_pointers
   Run:      ./06_pointers

   EXPECTED CORRECT OUTPUT:
     score starts at 12
     read through the pointer: 12
     after writing through the pointer: 20
     before swap: left 100, right 50
     after swap:  left 50, right 100
     heading was 350, wrapped to 350
     heading was 400, wrapped to 40
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
    while (heading >= 360) {
        *heading = *heading - 360;
    }
}

int main(void) {

    /* --- A: a pointer to an int ----------------------------- */
    int score = 12;
    int *p = score;

    printf("score starts at %d\n", score);
    printf("read through the pointer: %d\n", p);

    /* --- B: write through the pointer ----------------------- */
    p = 20;
    printf("after writing through the pointer: %d\n", score);

    /* --- C: swap two values using pointers ------------------ */
    int left  = 100;
    int right = 50;
    printf("before swap: left %d, right %d\n", left, right);
    swap(left, right);
    printf("after swap:  left %d, right %d\n", left, right);

    /* --- D: wrap a couple of headings ----------------------- */
    int heading1 = 350;
    wrapHeading(&heading1);
    printf("heading was 350, wrapped to %d\n", heading1);

    int heading2 = 400;
    wrapHeading(&heading2);
    printf("heading was 400, wrapped to %d\n", heading2);

    /* --- E: a pointer that was never pointed anywhere ------- */
    int *danglingPointer;
    *danglingPointer = 99;

    return 0;
}
