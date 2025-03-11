#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main() {
    char* ls_args[] = {
        "ls", "-la", NULL
    };
    int fork_id = fork();
    if (fork_id == -1) {
        fprintf(stderr, "error creating fork\n");
        return 1;
    }
    if (!fork_id) {
        execvp("ls", ls_args);
    }
}