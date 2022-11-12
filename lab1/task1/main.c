#include "stdio.h"
#include "unistd.h"
#include "sys/wait.h"

int main() {
    int pid0 = fork();

    if (pid0 == 0) {
        fork();
        sleep(30);
    } else {
        int pid2 = fork();

        if (pid2 == 0) {
            int pid3 = fork();
            if (pid3 != 0) {
	        fork();
	    }
            sleep(30);
        } else {
            fork();
            sleep(30);
        }
    }
    return 0;
}
