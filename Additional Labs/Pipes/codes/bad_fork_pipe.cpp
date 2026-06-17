#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char* argv[]) {
int p[2];
if (-1==pipe(p)) {
	perror("pipe");
	exit(1);
}
switch(fork()) {
case -1: perror("fork"); 
 exit(1);
case 0: {
	char c;
	int i=0;
	while (1==read(p[0],&c,1)) {
		i++;
		printf("Child has read %d byte%s\n",i,(i>1)?"s":"");
	}
	printf("Child has seen that the pipe has no more writer\n");
	close(p[0]);
	break;
}
default: {
	printf("Father writes 10 bytes and closes the pipe\n");
	char t[10];
	write(p[1],t,10);
	close(p[1]);
	printf("WARNING: the child process will remain blocked forever until you kill it!\n");
	break;
}
}
return 0;
}
