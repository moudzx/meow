#include <stdio.h>
#include <signal.h>
int main(){
printf("Avant le \"pause\" !\n");
pause();
printf("Après le \"pause\" !\n");
return 0;
}