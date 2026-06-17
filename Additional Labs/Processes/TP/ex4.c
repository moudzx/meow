#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

void main () {
	int code_retour;
	int fd=open("toto",O_RDWR|O_CREAT,0777);
	if(fd<0){
		perror("OPEN");
		exit(1);
	}
	char buf[8];
	int n;
	code_retour = fork ();
	switch (code_retour ) {
	case -1 :
	printf ("Pbm lors de la creation du processus\n");
	 break;
	case 0 :
	write(fd,"Child",5);
	sleep(2);
	 n=read(fd,buf,4);
	buf[n]='\0';
	printf("CHILD: %s\n",buf);
	break;
	default :
	sleep(1);
	 n=read(fd,buf,4);
	buf[n]='\0';
	printf("PARENT: %s\n",buf);
	write(fd,"Father",6);
	break;
	}
}
