/*

Exiting a thread
void pthread_exit(void *value_ptr);

value_ptr arg is a return value specified as an address
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_funct(void *a)
{
    const int loop = 8;
    int x;
    for (x = 0; x < loop; x++)
    { // Causing it to exit early
        if (x == 5)
            // The string Iam done is captured by pthread_join()
            pthread_exit("Iam done");
        printf("*\n");
        sleep(1);
    }
    return (NULL);
}

int main()
{
    char buffer[BUFSIZ];
    int r;
    pthread_t thd;
    void *retval;

    // Create new thread
    r = pthread_create(&thd, NULL, thread_funct, NULL);
    if (r != 0)
    {
        perror("Thread");
        exit(1);
    }
    // pthread_join() pauses the main thread until spawned thread runs to completion
    // 1st arg is  the thread handle thd
    // 2nd arg is the  address of a void pointer, retval.
    // This is the argument’s proper data type, which handles any return value.

    r = pthread_join(thd, &retval);
    if (r != 0)
    {
        perror("Thread join");
        exit(1);
    }
    // Below printf outputs the string captured by pthreadjoin() from pthreadexit
    // It then  cast it from void to a char pointer
    printf("%s\n", (char *)retval);

    printf("What is youre name");
    fgets(buffer, BUFSIZ, stdin);
    printf("Hello, %s", buffer);

    return (0);
}