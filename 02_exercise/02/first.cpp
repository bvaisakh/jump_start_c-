#include <stdio.h>

extern "C" int Add(int, int);

int main(int argc, char **argv)
{
    printf("hello world.. %d\n", Add(4, 6));
}