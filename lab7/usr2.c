#include <stdio.h>
#include <sys/types.h>
#include <signal.h>


int yourpid;
int cnt;

void sig_from_usr1(int signum){

    printf("usr1로부터 시그널을 잘 받았습니다.\n");
    kill(yourpid, SIGUSR1);
    exit(0);

}
int main ()
{
    signal(SIGUSR2, sig_from_usr1);

    pid_t pid;
	pid = getpid ();
	printf ("usr2 pid = %d \n", pid);

    scanf("%d", &yourpid); //user1 pid 입력하기
    pause();


}