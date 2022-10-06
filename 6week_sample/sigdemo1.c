#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void my_sig_handler(int signum){ printf("\nHI SIGNAL! I am KIM GAHEE\n"); }

int main(){
	void my_sig_handler(int);
	int i;
	signal(SIGINT, my_sig_handler);

	for(i = 0; i<100;i++){
		printf("hello\n");
		sleep(1);
	}
}
