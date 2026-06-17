#include "lib.h"
void main(int argc, char **argv){
int pd;
Message m;
unlink(PORT);

if(mkfifo(PORT,0777)<0){
	perror("Mkfifo");
	exit(1);
}

while(1){
	if( (pd=open(PORT,O_RDONLY))<0){
	perror("Mkfifo");
	exit(1);
	}
	read(pd,&m,sizeof(Message));
	if(strcmp("Fin",m.message)==0) break;
	printf("%s-%d\n",m.message,m.pidClient);
		
	}
close(pd);
}