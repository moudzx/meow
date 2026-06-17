#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
int n; 
char buffer[100];
void main (int argc, char* argv[])
{
int fd_read;
if ((fd_read=open(argv[1],O_RDONLY))==-1){
perror("open");exit(1);
}
if ((n=read(fd_read,buffer,100))==-1){
perror("read");
exit(2);
}
else {
buffer[n]='\0';
	puts(buffer);
}
close (fd_read);
}