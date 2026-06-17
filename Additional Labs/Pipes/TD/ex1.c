#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char* argv[]) {
int p[2];
if (-1==pipe(p)) {
	perror("pipe");
	exit(1);
}
fcntl(p[1],F_SETFL,O_NONBLOCK);

for (int i=1;;i++) {
	if (1!=write(p[1],"",1)) break; /* Writes a '\0' */
	printf("bytes written before 'write' blocks=%d\n",i);
}
return 0;
}
