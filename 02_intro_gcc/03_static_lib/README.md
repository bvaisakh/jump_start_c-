# Exercise 3 - Creating static library

- With GCC on Unix, you can use the archiver (`ar` command) to create static library
- `ar ru libArith.a first.o second.o`
- The `ru` option tells archiver to add given object files to the specified archive file if there are no existing members or update if they are latest.
- Traditionally, after an archive was created or updated, the tool `ranlib` was used to create or update the archive's symbol table. Now the archiver takes care of this.

## Compilation and Running

```bash
g++ -c ./third.cpp
g++ -c ./second.cpp
ar ru libArith.a second.o third.o
g++ -c ./first.cpp
g++ -o program.exe first.o libArith.a
./program.exe
```
