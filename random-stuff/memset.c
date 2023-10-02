/*
    memset is used to set  a block of memory to a specific value declaredin string.h

        syntax
                    void *memset(void *ptr, int value, size_t num);

        ptr => pointer  to the starting address of the memory you want to set
        value => Value you want to set in @ byte of the memory block
        num => no of bytes you want to set to the specfied value

    memset is usually used to initialize array or buffers to specific value eg 0
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int myArray[10];
    size_t size = sizeof(myArray);

    memset(myArray, 0, size);

    // All elements in array are now set to zero

    return 0;
}
