#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char* argv[]) {
int p[2];
if (-1==pipe(p)) {
	perror("pipe");
	exit(1);
}
for (int i=1;;i++) {
	write(p[1],"",1); /* Writes a '\0' */
	printf("bytes written before 'write' blocks=%d\n",i);
}
return 0;
}
