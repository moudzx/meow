#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int signum){
	system("mpg123 -q meow.mp3");
}

int main(){

	signal(SIGINT,handler);
	while(1);

	return 0;
}
