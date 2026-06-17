 #include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
 
void gestion_sigint (int signum){
  printf ("%u : SIGINT (CTRL+C), meme pas mal !\n", getpid ());
}
 
int main (void){
   if (signal (SIGINT, gestion_sigint) == SIG_ERR)
    fprintf (stderr, "Probleme d'interception SIGINT\n");
 
  while (1)     {     }
   return (0);
}
