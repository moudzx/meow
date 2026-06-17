#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

typedef struct {
pid_t pidClient;
char message[128];
} Message;

#define PORT "tube"