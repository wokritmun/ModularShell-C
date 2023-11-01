#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "command/executor.h"
#include <fcntl.h>
#include <unistd.h>

void process_command(char *command) {
    char *token = strtok(command, " \n");
    char *args[256];
    int arg_index = 0;
    char *output_file = NULL;
    bool redirect_output = false;

    while (token != NULL) {
        if (strcmp(token, ">") == 0) {
            redirect_output = true;
            token = strtok(NULL, " \n"); 
            output_file = token;
            break;
        }
        args[arg_index] = token;
        arg_index++;
        token = strtok(NULL, " \n");
    }
    args[arg_index] = NULL;  // Null terminate the list of arguments

    if (redirect_output && output_file) {
        int fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if (fd == -1) {
            perror("Shell Error");
            return;
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }

    execute_external_command(args);

    // Reset output redirection
    if (redirect_output) {
        dup2(STDOUT_FILENO, 1);
    }
}

