#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <wait.h>
#include <unistd.h>
#include <signal.h>


void handler(volatile int sig) {
    printf("SIGINT RECIEVED: CODE=%d\n", sig);
}
int value = 15;
int main() {
    signal(SIGINT, handler);
    int fork_id = fork();
    if (fork_id == -1) {
        fprintf(stderr, "Unable to create fork\n");
        return 1;
    }
    if (!fork_id) {
        --value;
        execlp("sleep", "sleep", "5", NULL);
        fprintf(stderr, "Error: Doesn't sleep\n");
        return 1;
    }
    int status;
    int pid = wait(&status);
    printf("PID: %d, STATUS: %d, %d\n", pid, status, WIFEXITED(status));
    if (WIFEXITED(status)) 
        printf("Exited with status: %d\n", WEXITSTATUS(status));
    printf("VALUE: %d\n", value);

}