#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


extern char ** environ;

int main() {
	char* uname_args[] = {
	       "uname", "-a"
	};	
	execve("/bin/uname", uname_args, environ);
	puts("Z");
}
