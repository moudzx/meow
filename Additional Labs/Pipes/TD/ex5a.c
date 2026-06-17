# include <stdlib.h>
# include <stdio.h>
 # include <unistd.h>
 # include <sys/wait.h>
 int p [2];
 void fils1 ( void )
 {
char c;
 close (p [0]);
 printf (" debut fils1 ( taper 0 pour finir )\n");
while ( ( c= getchar ()) != '0' )
 if ( ( c >= 'A' && c <= 'Z') || ( c >= 'a' && c <= 'z') )
 {
 if ((c >= 'a') && ( c <= 'z')) c -=32;
 write (p[1] ,&c ,1);
 printf (" Le fils1 envoie >%c <\n",c);
 }
 close (p [1]);
 exit ( EXIT_SUCCESS );
}
 void fils2 ( void )
 {
 char c;
 close (p [1]);
 printf (" debut fils2 \n");
 while ( read (p[0] ,&c ,1) > 0)
 printf (" fils2 recoit >%c <\n",c);
 close (p [0]);
 exit ( EXIT_SUCCESS );
 }
 int main ( void )
 {
 if ( pipe (p ) != 0)
 {
 printf (" pb ouverture pipe \n");
 exit ( EXIT_FAILURE );
 }
 if ( fork ()==0) fils1 ();
 if ( fork ()==0) fils2 ();
 close (p [0]); close (p [1]);
 wait ( NULL ); wait ( NULL );
 printf (" fin du pere \n");
 exit ( EXIT_SUCCESS );
 }