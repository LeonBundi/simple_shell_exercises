#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    while (1) {
        char command[100];
        printf("#cisfun$ ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';  /* Remove newline */
        
        if (strcmp(command, "exit") == 0) {
            break;
        }
        
        pid_t pid = fork();
        
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {  /* Child process */
            char *args[] = { command, NULL };
            execv(command, args);
            
            /* If execv fails, print an error */
            perror("execv");
            exit(EXIT_FAILURE);
        } else {  /* Parent process */
            int status;
            waitpid(pid, &status, 0);
        }
    }
    
    return 0;
}

