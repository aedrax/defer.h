#include <stdio.h>
#include <stdlib.h>
#include "defer.h"

int main()
{
    int *resource = malloc(sizeof(int));
    *resource = 42;
    printf("Allocated resource %d\n", *resource);
    DEFER({
        printf("Cleaning up resource %d\n", *resource);
        free(resource);
    });

    // Do something with the resource
    printf("Using resource %d\n", *resource);
    return 0;
    // End of block - resource is automatically cleaned up here
}