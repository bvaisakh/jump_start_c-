#include <stdio.h>

// extern "C" tells the C++ compiler that you have a function which was compiled by the C compiler.
// Once you tell it that it was compiled by the C compiler, the C++ compiler will know how to call it correctly.
// It also allows the C++ compiler to compile a C++ function in such a way that the C compiler can call it.
extern "C" int Add(int, int);

int main(int argc, char **argv)
{
    printf("hello world.. %d\n", Add(4, 6));
}