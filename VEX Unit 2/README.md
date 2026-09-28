# VEX Unit II — C / C++ Bug Hunt

Eight practice files that go with the **Unit II: C / C++ Fundamentals** slides.
Every file has a handful of bugs planted in it on purpose. Your job is to find
them, fix them, and get the program to print the **EXPECTED CORRECT OUTPUT**
that is written at the top of each file.

Some bugs stop the program compiling — the compiler yells at you, and those are
the easy ones. Others compile perfectly and just print the **wrong answer**.
Those are the dangerous ones, and they are the whole point of this unit: on a
robot, that is the bug that ruins an autonomous routine while everything *looks*
fine.

---

## 1. One-time setup

You need two things: a compiler, and the Code Runner extension.

### a) Install a C/C++ compiler

**Windows** — the easiest option is **MSYS2**:
1. Download and install from <https://www.msys2.org>.
2. Open the "MSYS2 UCRT64" terminal it installs and run:
   ```
   pacman -S mingw-w64-ucrt-x86_64-gcc
   ```
3. Add `C:\msys64\ucrt64\bin` to your PATH (search Windows for
   "Edit the system environment variables" → Environment Variables → Path →
   New → paste it in), then restart VS Code.

**Mac** — open Terminal and run `xcode-select --install`.

**Linux** — `sudo apt install build-essential` (or your distro's equivalent).

To check it worked, open a terminal and run `gcc --version` and `g++ --version`.
Both should print a version number.

### b) Install the Code Runner extension

In VS Code: open the Extensions panel (the squares icon on the left), search
for **Code Runner** (by Jun Han), and click Install.

---

## 2. How to run a file

1. Open **this folder** (`VEX Unit 2`) in VS Code — *File → Open Folder…*
   (The `.vscode` settings in here only work if this is the folder you open.)
2. Open any exercise, e.g. `01_variables.c`.
3. Click the **▶ Run button** in the top-right corner (or press `Ctrl+Alt+N`).

The program builds and runs in the terminal at the bottom. If it printed the
expected output, that file is done. If it won't build, read the **first** error
message, fix that one line, and run again.

> **If the program never finishes**, it has an infinite loop (a couple of files
> warn you about this). Click the terminal and press **Ctrl+C** to stop it, then
> go find the loop that never ends.

### Prefer the terminal?

You can skip Code Runner and compile by hand. Warnings (`-Wall`) matter here —
turn them on:

```bash
gcc -Wall 01_variables.c -o 01_variables   # C files:   01 02 03 04 06
./01_variables
```

```bash
g++ -Wall 05_functions.cpp -o 05_functions  # C++ files: 05 07 08
./05_functions
```

On Windows, run the built program with `.\01_variables.exe` instead of
`./01_variables`.

---

## 3. The files, in order

Work through them top to bottom — each one leans on the last.

| File | Lang | Topic | Bugs |
|------|------|-------|------|
| `01_variables.c` | C | types, integer division, printf | 5 |
| `02_if_logic.c` | C | bool, if/else, `==` vs `=`, braces | 5 |
| `03_for_loops.c` | C | for loops, arrays, off-by-one | 5 |
| `04_while_loops.c` | C | while, do-while, break/continue | 5 |
| `05_functions.cpp` | C++ | functions, return values, references | 5 |
| `06_pointers.c` | C | `&`, `*`, dereferencing | 6 |
| `07_arrays_structs.cpp` | C++ | vectors, structs, enum class | 5 |
| `08_robot_class.cpp` | C++ | classes (capstone) | 6 |

That is 42 bugs in total, and about 30 of them build without a single error.
The ratio is on purpose: the compiler catches the easy mistakes, and the field
catches the rest.

---

## 4. `solutions/` folder — try first!

Working versions of all eight files live in [`solutions/`](solutions). Give each
file an honest attempt (fifteen minutes minimum) **before** you look. There is
often more than one correct fix, so if yours differs from the solution but the
output matches, you are fine.

Coaches: the full bug-by-bug breakdown is in
[`BUGS-ANSWER-KEY.md`](BUGS-ANSWER-KEY.md).
