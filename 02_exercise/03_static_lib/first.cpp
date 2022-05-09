#include <stdio.h>

extern "C" int Add(int, int);
extern "C" int Mul(int, int);

int main(int argc, char **argv)
{
    printf(
        "hello world.. %d\t%d\n",
        Add(5, 25),
        Mul(4, 6));
}