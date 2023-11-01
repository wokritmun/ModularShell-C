#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "io/parser.h"


bool running = true;

int main() {
    char command[256];

    while (running) {
        printf("> ");  // Prompt for the user
        fgets(command, sizeof(command), stdin);

        if (strcmp(command, "exit\n") == 0) {
            running = false;
            continue;
        }

       process_command(command);
    }

    

    return 0;
}
