//(1) kill test


#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int pid, sig_num, result;
	if (argc != 3) {
		printf ("Needs pid signum\n");
		exit(0);
	}
	pid = atoi (argv[1]);
	sig_num = atoi (argv[2]);
	result = kill (pid, sig_num);
	printf ("result = %d\n", result);
}


//(2) time test

#include <stdio.h>
#include <time.h>

int main ()
{
	time_t ct;
	struct tm tm;
	ct = time (NULL);
	tm = *localtime (&ct);
	printf ("%d-%d-%d hour: %d, min : %d, sec: %d\n",
		tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, 
		tm.tm_min, tm.tm_sec);

}



//(3) alarm test

#include <stdio.h>
#include <signal.h>

void my_sig_handler (int signum)
{
	printf ("signum = %d \n", signum);
	printf ("Signal is caught. \n");
	alarm (5);
}

int main ()
{
	signal (SIGALRM, my_sig_handler);
	alarm (5);
	while (1) {
		printf ("Hello\n");
		sleep (2);
	}
}



//(4) pid get test

#include <stdio.h>
#include <sys/types.h>

int main ()
{

    pid_t pid;
	pid = getpid ();
	printf ("pid = %d \n", pid);
}