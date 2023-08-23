#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int i;
	pid_t pid;

	for (i = 0; i < 5; i++)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)/* Child process */
		{
			char *args[] = {"ls", "-l", "/tmp", NULL};
			execvp("ls", args);
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		else /* Parent process */
		{
			int status;
			wait(&status);

			if (WIFEXITED(status))
					printf("Child process %d exited with status %d\n", pid, WEXITSTATUS(status));
			else
			printf("Child process %d did not exit normally\n", pid);
		}
	}
return 0;
}

