#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    pid = fork();

    if(pid > 0)   // Parent process
    {
        printf("I am parent, my PID is %d\n", getpid());
        sleep(10);   // keep parent alive to see zombie in ps
    }
    else if(pid == 0)   // Child process
    {
        printf("I am child, my PID is %d\n", getpid());
        printf("My parent PID is: %d\n", getppid());
    }
    else
    {
        printf("Fork failed\n");
    }

    return 0;
}
