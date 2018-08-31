#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
size_t sigdepth = 0;
#define ifs(x) if(sig_num == x) printf("Signal recieved: %s\n", #x)
int sig_handler(int sig_num) {
	sigdepth++;
	ifs(SIGABRT);
	else ifs(SIGALRM);
	else ifs(SIGBUS);
	else ifs(SIGCHLD);
	else ifs(SIGCONT);
	else ifs(SIGEMT);
	else ifs(SIGEV_NONE);
	else ifs(SIGEV_SIGNAL);
	else ifs(SIGEV_THREAD);
	else ifs(SIGFPE);
	else ifs(SIGHUP);
	else ifs(SIGILL);
	else ifs(SIGINFO);
	else ifs(SIGINT);
	else ifs(SIGIO);
	else ifs(SIGIOT);
	else ifs(SIGKILL);
	else ifs(SIGPIPE);
	else ifs(SIGPROF);
	else ifs(SIGQUIT);
	else ifs(SIGSEGV);
	else ifs(SIGSTKSZ);
	else ifs(SIGSTOP);
	else ifs(SIGSYS);
	else ifs(SIGTERM);
	else ifs(SIGTRAP);
	else ifs(SIGTSTP);
	else ifs(SIGTTIN);
	else ifs(SIGTTOU);
	else ifs(SIGURG);
	else ifs(SIGUSR1);
	else ifs(SIGUSR2);
	else ifs(SIGVTALRM);
	else ifs(SIGWINCH);
	else ifs(SIGXCPU);
	else ifs(SIGXFSZ);
	else printf("Unknown Signal recieved: %d\n", sig_num);
	// may get stuck in recursive loop, attempt to avoid this
	if (sigdepth > 1) {
		puts("handler loop detected, exiting program");
		_Exit(-121);
	}
	sigdepth--;
	puts("i will now exit this program");
	_Exit(-120);
}

signal(SIGABRT, sig_handler);
signal(SIGALRM, sig_handler);
signal(SIGBUS, sig_handler);
signal(SIGCHLD, sig_handler);
signal(SIGCONT, sig_handler);
signal(SIGEMT, sig_handler);
signal(SIGEV_NONE, sig_handler);
signal(SIGEV_SIGNAL, sig_handler);
signal(SIGEV_THREAD, sig_handler);
signal(SIGFPE, sig_handler);
signal(SIGHUP, sig_handler);
signal(SIGILL, sig_handler);
signal(SIGINFO, sig_handler);
signal(SIGINT, sig_handler);
signal(SIGIO, sig_handler);
signal(SIGIOT, sig_handler);
signal(SIGKILL, sig_handler);
signal(SIGPIPE, sig_handler);
signal(SIGPROF, sig_handler);
signal(SIGQUIT, sig_handler);
signal(SIGSEGV, sig_handler);
signal(SIGSTKSZ, sig_handler);
signal(SIGSTOP, sig_handler);
signal(SIGSYS, sig_handler);
signal(SIGTERM, sig_handler);
signal(SIGTRAP, sig_handler);
signal(SIGTSTP, sig_handler);
signal(SIGTTIN, sig_handler);
signal(SIGTTOU, sig_handler);
signal(SIGURG, sig_handler);
signal(SIGUSR1, sig_handler);
signal(SIGUSR2, sig_handler);
signal(SIGVTALRM, sig_handler);
signal(SIGWINCH, sig_handler);
signal(SIGXCPU, sig_handler);
signal(SIGXFSZ, sig_handler);
