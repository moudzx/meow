# include <stdio.h>
 # include <stdlib.h>
 # include <unistd.h>
#include <sys/wait.h>
int gcd(int a, int b) {
if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main() {
int a, b, r;
int tube[2];
if(pipe(tube)==-1){
perror("error open pipe");
exit(0);
}
if(fork()==0){
close(tube[1]);
read(tube[0],&a,sizeof(int));
read(tube[0],&b,sizeof(int));
r = gcd(a,b);
printf("Child, gcd = %d\n",r);
exit(0);
}
close(tube[0]);
printf("enter a: ");
scanf("%d", &a);
printf("enter b: ");
scanf("%d", &b);
write(tube[1],&a,sizeof(int));
write(tube[1],&b,sizeof(int));
wait(NULL);
return 0;
}
