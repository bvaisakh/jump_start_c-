# Building shared objects

```bash
g++ -c second.cpp
g++ -c third.cpp
g++ -shared -fPIC -o libArith.so second.o third.o
g++ -o program.exe first.cpp ./libArith.so
./program.exe
```

## Questions

1. What is the significance of flags '-shared' and '-fPIC'?
    - '-shared': 