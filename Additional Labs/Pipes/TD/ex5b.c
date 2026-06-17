 # include <stdlib.h>
 # include <stdio.h>
 # include <unistd.h>
 # include <wait.h>
 void parent (int entree , int sortie )
 {
 unsigned char n = 0;
 write (sortie , &n , 1);
 n++; write (sortie , &n , 1);
 do {
 read ( entree , &n , 1);
 printf ("%u " , n); fflush ( stdout );
 write (sortie , &n , 1);
 } while (n <= 200);
printf ("\n");
 close ( sortie );
 wait ( NULL );
 }
 void enfant (int entree , int sortie )
 {
 unsigned char p,q;
 read ( entree , &p , 1);
 for (;;){
 write (sortie , &p , 1);
 if ( read ( entree , &q , 1) != 1) return ;
 p += q;
 }
 }
 int main ( void )
 {
 int tube_pe [2] , tube_ep [2] , pid;
 printf ("[% d ] : d´ebut du p`ere .\n", getpid ());
 pipe ( tube_pe ); /* tube Parent -> Enfant */
 pipe ( tube_ep ); /* tube Enfant -> Parent */
 if ( ( pid = fork ()) == -1) exit ( EXIT_FAILURE );
 if ( pid > 0){ /* parent */
 close ( tube_pe [0]); close ( tube_ep [1]);
 parent ( tube_ep [0] , tube_pe [1]);
 }
 else { /* enfant */
 close ( tube_pe [1]); close ( tube_ep [0]);
 enfant ( tube_pe [0] , tube_ep [1]);
 }
 printf ("[% d ] : terminaison \n", getpid ());
 exit ( EXIT_SUCCESS );
 }
