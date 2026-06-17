
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc,char* argv[]) {
if (argc==1) {
	printf("Usage: %s cmd ...\n",argv[0]);
	printf("Puts the output of a command in uppercase\n");
	return 1;
}
int p[2];
if (-1==pipe(p)) {
	perror("pipe");
	exit(1);
}
switch(fork()) {
case -1: perror("fork"); exit(1);
case 0: {
	/* The child will run the command, so we close its unused side of the pipe */
	close(p[0]);
	/* We redirect its output */
	dup2(p[1],1);
	/* And now that we have 2 descriptors on p[1], we must close one */
	close(p[1]);
	/* Finally, we run the command. Don't worry about closing p[1],
	 * the system will close all descriptors including this one
	 * when the command dies */
	execvp(argv[1],argv+1);
	perror("execvp");
	exit(1);
}
default: {
	/* The father will read from the pipe and write to the output, so
	 * we first close the unused side of the pipe.
	 *
	 * NOTE: it would have been a very unnecessary effort to redirect p[0]
	 *       in the standard input and then to read from 0. So, use your mind ;)
	 */
	close(p[1]);
	char c;
	while (1==read(p[0],&c,1)) {
		c=toupper(c);
		write(1,&c,1);
	}
	close(p[0]);
	break;
}
}
return 0;
}
