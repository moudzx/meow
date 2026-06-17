void sigpipe_hndlr(int signum) { printf("signal SIGPIPE recu\n");
}

int main () { int fd[2]; int nbytes;

struct sigaction sa; sa.sa_handler = sigpipe_hndlr; sigemptyset(&sa.sa_mask); sa.sa_flags = 0;
sigaction(SIGPIPE, &sa, NULL);

pipe(fd); close(fd[0]);

if (-1 == (nbytes = write(fd[1], "a", 1))) { perror("write fd[1]"); } else { printf("%d bytes written\n", nbytes); }
exit(EXIT_SUCCESS);
}
