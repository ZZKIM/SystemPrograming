
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>


int yourpid;
int cnt;

void sig_from_usr2(int signum){

    printf("usr2로부터 시그널을 잘 받았습니다.\n");

}
int main ()
{
    signal(SIGUSR1, sig_from_usr2);

    pid_t pid;
	pid = getpid ();
	printf ("usr1 pid = %d \n", pid);
    scanf("%d", &yourpid); //user2 pid 입력하기
    kill(yourpid, SIGUSR2);
    pause(0);
    exit(0);
}