#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *thread_funct(void *a)
{
    const int loop = 8;
    int x;

    for (x = 0; x < loop; x++)
    {
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

    // Create new thread

    r = pthread_create(&thd, NULL, thread_funct, NULL);
    if (r != 0)
    {
        perror("Thread");
        exit(1);
    }

    // Wait for thread_funct
    // When below () is called  main() suspends execution
    // until thread_funct thread runs its course
    r = pthread_join(thd, NULL);
    if (r != 0)
    {
        perror("Thread join");
        exit(1);
    }
    // Prompt for youre name
    printf("What is youre naame");
    fgets(buffer, BUFSIZ, stdin);

    return (0);
}

// First thread_funct is spawned then pthread_join is called
// Execution is suspended until thread_funct is done then
// User is prompted for name