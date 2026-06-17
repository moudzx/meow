#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<errno.h>

 void gestion_sigint (int signum) {  
fprintf (stderr, "%u : SIGINT (CTRL+C), même pas mal !\n", getpid ());
}
 

int main (void)
{  struct sigaction action;
  
  action.sa_handler = gestion_sigint;
  sigemptyset (&(action.sa_mask));
  action.sa_flags = 0;
  
   if ( sigaction (SIGINT, &action, NULL) != 0)    {
      fprintf (stderr, "Erreur de gestion %d\n", errno);
      exit (1);    }
   while (1)    {     }
   return (0); }
