

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char* argv[]) {
int p[2];
if (-1==pipe(p)) {
	perror("pipe");
	exit(1);
}
char c;
read(p[0],&c,1);
return 0;
}
