// Demonstrating type casting => which is the converting from one datatype to another

#include <stdio.h>
main()
{
    int sum = 17, count = 5;
    double mean;

    mean = (double)sum / count;

    printf("VAlue of mean : %f\n", mean);
}