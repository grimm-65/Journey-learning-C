#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *threaad_funct(void *a)
{

    const int loop = 8;
    int x;

    for (x = 0; x < loop; x++)
    {
        printf("%s\n", (char *)a);
        sleep(1);
    }
    return (NULL);
}

int main()
{
    char buffer[BUFSIZ];
    int r;
    pthread_t thd1, thd2, thd3;

    /*CREATE THREAD 1*/
    r = pthread_create(&thd1, NULL, threaad_funct, "*");
    if (r != 0)
    {
        perror("Thread");
        exit(1);
    }
    /*CREATE THREAD 2*/
    r = pthread_create(&thd2, NULL, threaad_funct, "#");
    if (r != 0)
    {
        perror("Thread");
        exit(1);
    }

    /*CREATE THREAD 3*/
    r = pthread_create(&thd3, NULL, threaad_funct, "+");
    if (r != 0)
    {
        perror("Thread");
        exit(1);
    }
    /*Prompt for user name*/
    printf("What is youre name");
    fgets(buffer, BUFSIZ, stdin);
    printf("Hello, %s", buffer);

    return 0;
}