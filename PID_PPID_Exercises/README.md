#PID & PPID
A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, you can use the system call getpid (man 2 getpid):

julien@ubuntu:~/c/shell$ cat pid.c
\#include <stdio.h>
\#include <unistd.h>

/**
 \* main - PID
 *
 \* Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("%u\n", my_pid);
    return (0);
}
julien@ubuntu:~/c/shell$ gcc -Wall -Werror -pedantic pid.c -o mypid && ./mypid
3237
julien@ubuntu:~/c/shell$ ./mypid 
3238
julien@ubuntu:~/c/shell$ ./mypid 
3239
julien@ubuntu:~/c/shell$ 
Note in the example above, that every time you run the program, a new process is created, and its ID is different.

Each process has a parent: the process that created it. It is possible to get the PID of a parent process by using the getppid system call (man 2 getppid), from within the child process.

##Exercises
0. getppid
Write a program that prints the PID of the parent process. Run your program several times within the same shell. It should be the same. Does echo $$ print the same value? Why?

1. /proc/sys/kernel/pid_max
Write a shell script that prints the maximum value a process ID can be.
