// Fork splits a program into 2 processes each capable of handling
// different tasks simultaneously

// fork splits the  program into 2 parts
// code uses pid to defferntiate parent from child

#include <stdio.h>
#include <unistd.h>

int main()
{
    __pid_t parent, a, b;

    // getpid() => Gets the process ID of the calling process.
    // parent  pid  is stored in parent
    parent = getpid();

    fork();
    // After fork() a will hold current process id
    // if it is same to that of the parent printf

    a = getpid();
    if (a == parent)
    {
        printf("Iam the parent %d\n", parent);
    }
    else
    {
        fork();
        // var b is assigned the curent pid
        b = getpid();
        if (a == b)
        {
            printf("Iam the child %d\n", a);
        }
        else
        {
            printf("Iam the grand child %d\n", b);
        }
    }

    // printf("The pid of parent is %d\n", parent);

    return 0;
}