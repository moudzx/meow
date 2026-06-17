#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>

typedef struct 
 {
   pid_t pid_client;
   char message[50];
 }Donnees;

#define PIPE "TUBE"