#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>


 int main (void)
{  int i;

   for (i = 0; i < NSIG; i++)
	printf ("%d : %s\n", i, sys_siglist[i]);
    
for (i = 0; i < NSIG; i++)   {
      fprintf (stderr, "%d", i);
      psignal (i, " ");    }

   for (i = 0; i < NSIG; i++)
          printf ("%d : %s\n", i, strsignal (i));
     
  return (0);
}
