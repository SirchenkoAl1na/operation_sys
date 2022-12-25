#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"
#include <stdlib.h>

int main(int argCount, char *arg[]) {
    int status;

    char* command = arg[1];
    char* arguments[argCount - 1];
    for (int i = 1; i <= argCount; i++) {
        arguments[i - 1] = arg[i];
    }

    int pid = fork();
    if (pid == 0) {
        execvp(command, arguments);
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        if (status == 0) {
            printf("Success!\n");
        } else {
            printf("Failed, exit code = %d\n", status);
        }
    }

    return 0;
}
