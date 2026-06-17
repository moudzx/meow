#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void operation(char op,int op1,int op2){
switch(op){
case '+': printf("%d %c %d =%d\n",op1,op,op2,op1+op2);break;
case '-': printf("%d %c %d =%d\n",op1,op,op2,op1-op2);break;
case '*': printf("%d %c %d =%d\n",op1,op,op2,op1*op2);break;
case '/': printf("%d %c %d =%d\n",op1,op,op2,op1/op2);break;
}
}
void main(){

int tube[2];
int a,b;
char c;

if(pipe(tube)<0){
perror("Pipe");
exit(1);
}
switch(fork()){
case -1: perror("fork");exit(1);
case 0:close(tube[1]);

while(1){
read(tube[0],&c,1);
if(c=='#') exit(0);
read(tube[0],&a,4);
read(tube[0],&b,4);
operation(c,a,b);
}

default:close(tube[0]);
while(1){
printf("operateur?(+,-,*,/) # pour terminer?");
c=getchar();
getchar();
write(tube[1],&c,1);

if(c!='#'){
printf("operand 1?");
scanf("%d",&a);
write(tube[1],&a,4);
printf("operand 2?");
scanf("%d",&b);getchar();
write(tube[1],&b,4);
}
else exit(0);
}
}
}