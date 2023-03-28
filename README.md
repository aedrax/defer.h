# Defer.h
This is a simple C header wrapper for implementing defer statements similar to
those found in Go. The defer.h header file provides a single macro, `DEFER`,
which can be used to simplify resource management and ensure that resources are
automatically cleaned up when they are no longer needed. The macro takes
advantage of the cleanup attribute in gcc and clang. This repo is inspired by
the work originally done by
[smokris](https://fdiv.net/2015/10/08/emulating-defer-c-clang-or-gccblocks) and
[Baruch Even](https://gist.github.com/baruch/f005ce51e9c5bd5c1897ab24ea1ecf3b)

## Usage
### `DEFER`
The `DEFER` macro is used to define a cleanup function that is called when the
block of code containing the `DEFER` macro ends. It takes a single argument:

The code to execute when the block ends.
#### Example:

```c
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
    // End of block - resource is automatically cleaned up here

    // Do something with the resource
    printf("Using resource %d\n", *resource);
    return 0;
}
```

In this example, we use the `DEFER` macro to automatically free a dynamically
allocated integer when the block of code containing the `DEFER` macro ends.
The cleanup function defined by the `DEFER` macro frees the resource and prints
a message to the console.

By using the `DEFER` macro in this way, we can simplify resource management and
ensure that resources are automatically cleaned up when they are no longer
needed.

#### Example
Here is an example program that uses defer.h to automatically cleanup a
dynamically allocated integer when it is no longer needed:

```c
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
    // End of block - resource is automatically cleaned up here

    // Do something with the resource
    printf("Using resource %d\n", *resource);
    return 0;
}
```

In this example, we allocate a resource using malloc, and then use the `DEFER`
macro to define a cleanup function that frees the resource when the block ends.
We also use the resource inside the block and print its value to the console.

When the block ends, the cleanup function defined by the `DEFER` macro is
automatically called, freeing the resource and ensuring that it is not leaked.

By using the `DEFER` macro in this way, we can simplify resource management and
ensure that resources are automatically cleaned up when they are no longer
needed.