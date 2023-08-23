#File information
The stat (man 2 stat) system call gets the status of a file. On success, zero is returned. On error, -1 is returned.

julien@ubuntu:~/c/shell$ cat stat.c
\#include <stdio.h>
\#include <sys/types.h>
\#include <sys/stat.h>
\#include <unistd.h>

/**
 \* main - stat example
 *
 \* Return: Always 0.
 */
int main(int ac, char **av)
{
    unsigned int i;
    struct stat st;

    if (ac < 2)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return (1);
    }
    i = 1;
    while (av[i])
    {
        printf("%s:", av[i]);
        if (stat(av[i], &st) == 0)
        {
            printf(" FOUND\n");
        }
        else
        {
            printf(" NOT FOUND\n");
        }
        i++;
    }
    return (0);
}
julien@ubuntu:~/c/shell$ ./stat ls /bin/ls /usr/bin/ls
ls: NOT FOUND
/bin/ls: FOUND
/usr/bin/ls: NOT FOUND
julien@ubuntu:~/c/shell$ 

##Exercise: find a file in the PATH
Write a program that looks for files in the current PATH.

Usage: _which filename ...
