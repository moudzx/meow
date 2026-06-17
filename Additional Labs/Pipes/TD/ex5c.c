//Que ce passe-t-il pendant l’exécution du
//programme tubonacci.c suivant ?
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
 void parent (int entree , int sortie )
 {
 //unsigned char n = 0;
//unsigned char n = 2;
int n = 2;
 write (sortie , &n , sizeof(int));
 n++; 
 write (sortie , &n , sizeof(int));
 do {
 read ( entree , &n , sizeof(int));
 printf ("%d " , n); 
fflush ( stdout );
 write (sortie , &n , sizeof(int));
 } //while (n <= 200);
while (n<1000);
 printf ("\n");
 close ( sortie );
 wait ( NULL );
 }
 void enfant (int entree , int sortie )
 {
 //unsigned char p,q;
int p,q;
 read ( entree , &p , sizeof(int));
 write (sortie , &p , sizeof(int));
  read ( entree , &p , sizeof(int));
 for (;;){
 write (sortie , &p , sizeof(int));
 if ( read ( entree , &q , sizeof(int)) != 4){
 return ;}
 p =2*p+ 3*q;

//p+=q;
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
 exit( EXIT_SUCCESS );
 }