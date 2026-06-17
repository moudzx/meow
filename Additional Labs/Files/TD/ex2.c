#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char**argv){
int per;
char cmd[50];

if(argc <3){
fprintf(stderr,"Using: %s fileName permessions\n",argv[0]);
exit(EXIT_FAILURE);
}

sscanf(argv[2],"%o",&per);

if(open(argv[1],O_CREAT|O_WRONLY|O_EXCL,per)<0)
{
perror("OPEN");
exit(EXIT_FAILURE);
}
else
fprintf(stdout,"File %s created\n",argv[1]);


sprintf(cmd,"ls -l %s",argv[1]);
system(cmd);
}