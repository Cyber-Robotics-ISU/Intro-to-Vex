# Answer key — Unit II.B practice files

**Coaches only.** Students should spend at least fifteen minutes per file
before seeing this. Working versions are in `solutions/`.

Each bug is labelled **[compile]** if it stops the build, or **[silent]** if
the program builds and simply produces the wrong answer. Silent bugs are the
ones worth teaching; they are the category that ruins an autonomous routine.

---

## 01_variables.c — 5 bugs

| # | Bug | Type | Fix |
|---|---|---|---|
| 1 | `int motorPort = 7` has no semicolon | compile | Add `;`. Note the error is reported on the *next* line. |
| 2 | `totalTicks = totalTicks + reading1 + ...` reads `totalTicks` before it holds anything | silent | `totalTicks = reading1 + reading2 + reading3;` |
| 3 | `totalTicks / 3` is int ÷ int, so 1080/3 works but the decimal is discarded in general | silent | `/ 3.0` |
| 4 | `printf("%d", wheelDiameter)` uses an int specifier for a `double` | silent | `%.2f` |
| 5 | `int 2ndMotorPort` starts with a digit | compile | Rename to `secondMotorPort`, in the declaration **and** the `printf`. |

**Teaching point:** bugs 2, 3 and 4 all compile. Only the expected-output
block in the header reveals them.

---

## 02_if_logic.c — 5 bugs

| # | Bug | Type | Fix |
|---|---|---|---|
| 1 | `bool`, `true`, `false` used with no `#include <stdbool.h>` | compile | Add the include. C++ has `bool` built in; C does not. |
| 2 | `if (temp = 55)` assigns instead of comparing, and the threshold is wrong | silent | `if (temp > 55)` |
| 3 | `if (hue < 20 \|\| > 340)` — the right side has no left operand | compile | `hue < 20 \|\| hue > 340` |
| 4 | The proximity guard prints its message but does not stop the function, so a colour is still reported when nothing is in front of the sensor | silent | Add `return;` inside that `if` |
| 5 | `safetyCheck` has no braces, so the second `printf` runs unconditionally | silent | Wrap both lines in `{ }` |

**Teaching point:** bug 5 is why the deck says *always use braces*. `-Wall`
catches it with `-Wmisleading-indentation`.

---

## 03_for_loops.c — 5 bugs

| # | Bug | Type | Fix |
|---|---|---|---|
| 1 | Countdown uses `i++` so `i > 0` is never false | hangs | `i--` |
| 2 | `i <= MOTOR_COUNT` reads `temps[4]` on a 4-element array | silent | `i < MOTOR_COUNT` |
| 3 | Too-hot test uses `> 45`, so a 47 °C motor is also flagged | silent | `> 55` |
| 4 | `int total;` is never set to 0 before `total = total + ...` | silent | `int total = 0;` |
| 5 | Stray `;` after `for (...)` in section E — the loop body is empty and the block below runs once with `i` out of scope | compile | Delete the `;` |

---

## 04_while_loops.c — 5 bugs

| # | Bug | Type | Fix |
|---|---|---|---|
| 1 | Section A never increments `count` | hangs | Add `count++;` inside the loop |
| 2 | `} while (attempts < 3)` has no semicolon | compile | Add `;` |
| 3 | Section C prints before moving, so it shows 1000 and never shows 600 | silent | Swap the two lines: decrement first, then print |
| 4 | `continue` jumps past `port++`, so `port` stays 3 forever | hangs | Increment before `continue` |
| 5 | `if (loops = 4)` assigns 4, which is true, so it breaks on the first pass | silent | `==` |

---

## 05_functions.cpp — 5 bugs

| # | Bug | Type | Fix |
|---|---|---|---|
| 1 | All four functions are defined *below* `main`, which uses them | compile | Add prototypes above `main` (already done in the solution) |
| 2 | Circumference uses `diameter * 2 * pi`, which is the radius formula | silent | `WHEEL_DIAMETER * 3.14159` |
| 3 | `motorTurns * 360.0;` computes a value and throws it away | silent | Add `return` |
| 4 | `clampInPlace(int value)` takes a copy, so the caller never changes | silent | `int &value` |
| 5 | `(a + b) / 2` is int ÷ int, so 227/2 gives 113 not 113.5 | silent | `/ 2.0` |

**Teaching point:** bug 3 is the single most instructive one here. `-Wall`
reports both *statement has no effect* and *no return statement*, and the
function silently returns garbage.

---

## 06_pointers.c — 6 bugs

| # | Bug | Type | Fix |
|---|---|---|---|
| 1 | `while (heading >= 360)` compares the pointer, not what it points at | silent | `*heading >= 360` |
| 2 | `int *p = score;` assigns a value where an address belongs | silent | `&score` |
| 3 | `printf(..., p)` prints the address, not the value | silent | `*p` |
| 4 | `p = 20;` re-points the pointer at address 20 | silent | `*p = 20;` |
| 5 | `swap(left, right)` passes copies, so nothing is swapped | compile | `swap(&left, &right)` |
| 6 | `danglingPointer` is dereferenced without ever pointing anywhere | crash | Point it at a real variable first |

**Teaching point:** bugs 2, 3 and 4 all compile with warnings only. This is
the file that shows why `-Wall` is not optional.

---

## 07_arrays_structs.cpp — 5 bugs

| # | Bug | Type | Fix |
|---|---|---|---|
| 1 | `sizeof(ports)/sizeof(ports[0])` inside a function — an array parameter is really a pointer, so this gives 2, not 4 | silent | Pass the length as a second parameter |
| 2 | `i <= readings.size()` reads one past the end of the vector | silent | `i < readings.size()`, and use `size_t` for `i` |
| 3 | `robot->heading` uses arrow on a non-pointer | compile | `robot.heading` |
| 4 | `lift == SCORE` — an `enum class` name must be qualified | compile | `LiftState::SCORE` |
| 5 | `for (Motor m : motors)` copies each motor, so the originals are untouched | silent | `for (Motor &m : motors)` |

**Teaching point:** bug 5 is exactly the mistake the deck warns about when
configuring a list of drive motors.

---

## 08_robot_class.cpp — 6 bugs (capstone)

| # | Bug | Type | Fix |
|---|---|---|---|
| 1 | No `;` after the closing brace of `class Intake` | compile | Add `};` |
| 2 | `intake.port` is private and accessed from `main` | compile | Use `intake.getPort()` |
| 3 | The constructor never sets `currentSpeed` | silent | Set it to 0 in the constructor |
| 4 | Toggle loop uses `i <= 2`, so it toggles three times and ends closed | silent | `i < 2` |
| 5 | `if (clampClosed = true)` assigns, so it is always true | silent | `==`, or just `if (clampClosed)` |
| 6 | `total / 4` is int ÷ int, giving 47 instead of 47.5 | silent | `/ 4.0` |

**Teaching point:** bug 6 is bug 3 from file 01 wearing different clothes. If
a student fixes it without recognising it, send them back to `01_variables.c`.

---

## Summary

| | Compile errors | Silent bugs | Hangs / crashes |
|---|---|---|---|
| Total across all 8 files | 12 | 26 | 4 |

That is 42 bugs in total, and 30 of them build without a single error.
Roughly seven in ten compile cleanly. The ratio is deliberate and
matches real robot code: the compiler catches the easy mistakes, and the field
catches the rest.
