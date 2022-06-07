# Exercise - 2

<https://github.com/praseedpai/COMNativeCode2009/blob/master/GCCCPP.pdf>

## extern "C"

- extern "C" tells the C++ compiler that you have a function which was compiled by the C compiler.
- Once you tell it that it was compiled by the C compiler, the C++ compiler will know how to call it correctly.
- It also allows the C++ compiler to compile a C++ function in such a way that the C compiler can call it.

## Creating static library

- With GCC on Unix, you can use the archiver (`ar` command) to create static library
- `ar ru libArith.a first.o second.o`
- The `ru` option tells archiver to add given object files to the specified archive file if there are no existing members or update if they are latest.
- Traditionally, after an archive was created or updated, the tool `ranlib` was used to create or update the archive's symbol table. Now the archiver takes care of this.

## Getting mangled name in a shared object
```bash
nm libArith.so | grep Add
```