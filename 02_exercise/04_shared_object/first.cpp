#include <stdio.h>

extern "C" int Add(int a, int b);
extern "C" int Mul(int a, int b);

int main(int argc, char **argv)
{
    printf(
        "hello world;\t sum: %d;\t product: %d\n",
        Add(5, 5),
        Mul(5, 5)
    );
}