#include <stdio.h> 
#include <sys/stat.h> 
#include <signal.h> 
void main(int argc, char **argv) 
{ 
int i,tube[2],pid; 
char c,buf[1024]; 
pipe(tube); 
pid = fork(); 
if (!pid) 
{ 

/* Le fils exécute la première commande */ 
close(1); 
dup(tube[1]); // ou bien dup2(tube[1],1);
close(tube[1]);close(tube[0]); 
system(argv[1]); 
exit(0); 
} 
/* Le père exécute la deuxième commande */ 
close(0); 
dup(tube[0]); // ou bien dup2(tube[0],0);
close(tube[1]); 
close(tube[0]); 
system(argv[2]); 
} 
