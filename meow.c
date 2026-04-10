#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

volatile sig_atomic_t meow = 0;

void handlerC(int signum){
    meow = 1;
}

void handlerZ(int signum){
	kill(getpid(),SIGKILL);
}

int main(){

	struct sigaction sa = {0};
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);

	sa.sa_handler = handlerC;
	sigaction(SIGINT, &sa, NULL);

        sa.sa_handler = handlerZ;
        sigaction(SIGTSTP, &sa, NULL);

	while(1){
		pause();
		if (meow){
			meow = 0;
			system("mpg123 -q meow.mp3");
		}
	}

	return 0;
}
