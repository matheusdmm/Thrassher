# Thrassher

Simple mark and sweep garbage collector in C.

#   How it works

It creates a graph-like  thing of reachable objects within the code and checks whether they're in use or not. If not in use and without anymore references, clean up the memory address and leave space to another objects and then repeat it all over again.

#   What is mark and sweep

The code travel starting at the roots, then pass through the entire object graph and every time you see an object and use it, the code will mark it to a "true" state untill you wont call it anymore.

When its done, the code will get all those objects and check if they're still marked true, and if not, delete them.

## /Etc

```bash
gcc main.c -o
```

It was made using [IntelliJ Clion](https://www.jetbrains.com/clion/), [C language](https://www.iso.org/standard/74528.html), [GCC](https://gcc.gnu.org/), [C language](https://www.iso.org/standard/74528.html) and [Based on Baby's first garbage collector by Nob Nystrom](http://journal.stuffwithstuff.com/2013/12/08/babys-first-garbage-collector/) // [and John McCarthy the man himself garbage collector](https://iq.opengenus.org/john-mccarthy/)
