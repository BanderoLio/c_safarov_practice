#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>


int main() {
	int uid = getuid();
	struct passwd* pwdp = getpwuid(uid);
	printf("UID: %d\nPID: %d\nPPID: %d\nUSER: %s\n", uid, getpid(), getppid(), pwdp->pw_name);
	sleep(15);
}

