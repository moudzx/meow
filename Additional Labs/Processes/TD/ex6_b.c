#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(){/*
if(fork()){ //b
if(fork()){ //c

if(!fork())//d
 fork()&&fork();
//e       f     
}

}
*/

if(fork()&&fork()&&!fork())
	fork()&&fork();
sleep(15);

}