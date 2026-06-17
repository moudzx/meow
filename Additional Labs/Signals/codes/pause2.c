#include <stdio.h>
#include <signal.h>
int main(){
signal(SIGINT, SIG_IGN); // Ignorer le signal SIGINT
printf("Avant le \"pause\" !\n");
pause();
printf("Après le \"pause\" !\n");
return 0;
}