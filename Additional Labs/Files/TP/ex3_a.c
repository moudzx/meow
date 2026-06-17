#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
void main(int argc, char**argv){
	
if(argc<2){
	fprintf(stderr,"Use : %s fileName\n",argv[0]);
exit(1);
}
int fd=open(argv[1],O_RDONLY);
if(fd<0){
	perror("Open");
	exit(1);
}
struct stat st;
if(fstat(fd,&st)<0){
perror("FSTAT");
	exit(2);	
}

if(S_ISREG(st.st_mode)){
	char c;
	while(read(fd,&c,1)>0)
		write(1,&c,1);
	
}

}