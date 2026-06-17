#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
char buf[1];
int tube[2], tube2[2];
pipe(tube2);
pipe(tube);
switch (fork ()){
case -1: perror("fork"); exit(-1);
case 0: {
read(tube[0],buf,1);
printf("ca\n");
write(tube2[1],"1",1);
exit(0);
}
default:
printf("wow\n");
write(tube[1],"1",1);
read(tube2[0],buf,1);
printf("compile\n");
wait(NULL);
return 0;
}
}