#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
    int f = fork();
    if (f != 0) {
        f = fork();
    }
    if (f == 0) {
        printf("Child PID: %d\n", getpid());
        srand(time(NULL));
        sleep(rand() % 16 + 5);
        printf("Process finished!\n");
        exit(3);
    }
    else {
        printf("Hi I'm a parent!\n");
        int status;
        int child_pid = wait(&status);
        if (child_pid) {
            if (WEXITSTATUS(status) == 3) {
                printf("Child process completed with pid %d\n", child_pid);
            }
        }
    }
    return 0;
}