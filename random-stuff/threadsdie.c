/*
A thread ends in one of 3 ways
    Natural causes
    Early exit
    Sudden death
*/
/*
To kill a thread
    pthread_cancel()
        it takes only one arg pthread_t value
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
// Definition of a () that takes asingle arg p and returns a void
// The use of void* indicates that this function can receive and
// return a pointer of any data type, as it is a generic pointer type.

void *eternal(void *p)
{
    // Creates a loop that has no termination condition
    // It will run indefinately until its explicitly terminated from the inside
    for (;;)
    {
        printf("On i go ... \n");
        sleep(1);
    }
}

int main()
{
    pthread_t thd;
    int r;

    puts("Launching endless thread ...");

    // Spawn a thread
    r = pthread_create(&thd, NULL, eternal, NULL);
    if (r != 0)
    {
        perror("Thread");
        exit(1);
    }
    puts("Press Enter to kill the thread");
    getchar();
    pthread_cancel(thd);
    puts("Thread terminated");

    puts("Press Enter to quit");
    getchar();

    return (0);
}

/*
    perror  is a standard lib used to report error messages

    when a function in c/c++ standard lib encounters an error is sets `errno` var
    to a specific value that rep the type of error that occured


    it takes 1 arg a string and the n appends a colon  and a space followed by the
     error message corresponding to the current value of errno

*/