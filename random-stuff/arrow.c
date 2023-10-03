#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

// Create a struct

struct student
{
    char name[80];
    int age;
    float percentage;
};

// Creating structure object
struct student *emp = NULL;

int main()
{
    // ASsigning memory to struct var emp
    emp = (struct student *)
        malloc(sizeof(struct student));

    // ASsigning val to age var of emp using arrow operator

    emp->age = 69;

    // Printing the assigned val to the var

    printf("%d", emp->age);

    return 0;
}