#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char **argv)
{
    int (*fn)(int, int);
    char *error;
    void *handle = dlopen("./libArith.a", RTLD_LAZY);

    if (handle == 0)
    {
        printf("Failed to load the program ...\n");
        return 0;
    }

    dlerror();

    *(void **)(&fn) = dlsym(handle, "Add");

    if ((error = dlerror()) != NULL)
    {
        printf("%s\n", error);
        exit(EXIT_FAILURE);
    }

    int nc = (*fn)(10, 15);
    printf("Sum is %d \n", nc);
    dlclose(handle);
}