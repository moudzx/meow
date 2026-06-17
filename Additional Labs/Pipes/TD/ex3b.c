#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){

switch (fork ()){
case -1: perror("fork"); exit(-1);
case 0: {
sleep(1);
printf("ca\n");
exit(0);
}
default:
printf("wow\n");
sleep(2);
printf("compile\n");
wait(NULL);
return 0;
}
}