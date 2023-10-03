// Using threads a function can run as its own thread and runs independently from the rest of the code
// Best practice to use local variables
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h> //pthread_ family of functions are prototyped

// to build -lpthread

// Create new thread
// int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);

// First arg is the address of a pthread_t value it references the thread in other pthread_family functions

// 2nd arg  sets various thread attributes. This value is NULL most of the time.

// 3rd arg name of the function to launch as another thread {must use void args for flexibility}

// 4th arg consists of any arguments passed to the function, or NULL for none.

// The function that runs the thread has this prototype
// void *(*start_routine)(void *)

// This format identifies the function that’s launched into its own thread, running independently of the rest of the code

// SAMPLE EXAMPLE

// Below code prompts you for youre name and also launches the thread_funct()
// function as a separate thread
// thread_funct() outputs asterisks every second

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

    /*Spawn new thread*/
    r = pthread_create(&thd, NULL, thread_funct, NULL);
    // incase of error pthread returns value other than zero
    if (r != 0)
    {
        perror("Thread");
        exit(1);
    }

    /*Prompt for youre Name*/
    printf("What is youre name?");

    // fgets() used to read lines from an input stream
    // buffer This is the character array (or string) where the input line will be stored
    // BUFSIZ It's a constant that represents the size of the buffer
    // stdin is a predefined file pointer that represents the standard input stream,which is typically the keyboard when you're working with a terminal.

    /*
    When you execute fgets(buffer, BUFSIZ, stdin);, the function will wait for the user
    to input a line of text followed by the Enter (Return) key.
    It will then read that line of text, including any whitespace characters, up to and including the newline character ('\n'),
    and store it in the buffer character array.
    */
    fgets(buffer, BUFSIZ, stdin);

    printf("Hello, %s", buffer);

    return 0;
}

/*THE ABOVE PROGRAM PROMTS USER TO INPUT HIS NAME
    which is then stored in buffer which   is character array defined earlier of
    size    BUFSIZ ,stdin is where user input will be coming from ie keyboard


*/