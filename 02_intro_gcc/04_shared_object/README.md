# Building shared objects

```bash
g++ -c second.cpp
g++ -c third.cpp
g++ -shared -fPIC -o libArith.so second.o third.o
g++ -o program.exe first.cpp ./libArith.so # static linking
./program.exe
```

## Questions

1. What is the significance of flags `-shared` and `-fPIC`?
  - `-shared`
    - Option for linking
    - Produces a shared object.
    - For predictable results, you must also specify the same set of options that were used to generate code (-fpic or -fPIC)
    - On some systems, `gcc -shared` needs to build supplimentary stub code for constructors to work.
  - `-fPIC`
    - Option for code generation convention
    - If supported for the target machine emits position-independent code, suitable dynamic linking
    - `-fPIC` avoids any size limit of the global offset table.
    - Position-independent code accesses all constant addresses through a global offset table (GOT). 
    - The dynamic loader resolves the GOT entries when the program starts. (Dynamic loader is part of the operating system)

2. Why position independent code is significant for shared libraries?
