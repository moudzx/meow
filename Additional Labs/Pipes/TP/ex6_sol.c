#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void main(){
int data[100];
int i, n, index;
int cp[2],pc[2];
char c = '.';
for(i = 0; i < 100; i++)
  data[i] = rand() % 100;
if(pipe(cp)==-1 || pipe(pc)==-1){
perror("pipe");
exit(EXIT_FAILURE);
}
printf("Enter the number: ");
scanf("%d", &n);
switch(fork()){
case -1: perror("fork");
exit(EXIT_FAILURE);
break;
case 0: close(cp[0]);
close(pc[1]);
read(pc[0],&c,1);
index = -1;
for(i = 50; i < 100; i++) {
if(n==data[i]){
  index = i;
  break;
}}
write(cp[1],&index,sizeof(int));
break;
default: close(cp[1]);
close(pc[0]);
for(i = 0; i < 50; i++){
if(n==data[i]) {
printf("Number found by parent at index %d\n", i);
exit(0);
}
write(pc[1],&c,1);
read(cp[0],&index,4);
if(index==-1)
printf("Number not found\n");
else
printf("Number found by child at index %d\n", index);
} 
}
}
