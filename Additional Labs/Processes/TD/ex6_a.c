#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(){
/*
if(fork()){
if(fork())
fork();
}else
{
if(fork()==0)
fork();
}
*/

if(fork()){
fork()&&fork();
}else
{
fork()||fork();
}

sleep(15);

}