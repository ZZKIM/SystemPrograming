#include <stdio.h>
#include <signal.h>

void my_alarm_handler (int signum)
{
	printf ("signum = %d \n", signum);
	printf ("Signal is caught. \n");
	alarm (5); //응용 버전 : 이거 또 만나면 또 5초 후에 시그널 발생 : 즉 결국에는 5초마다 printf가 발생한다.
    //5초에 한번씩 이벤트가 있다 근데 원래 할일도 있다 라고 하면 이런식으로 프로그램을 짜면 된다. (sleep은 멈춰있는건데 얘는 아니니까.)
}

int main ()
{
	signal (SIGALRM, my_alarm_handler); //함수 호출 아님.
	alarm (5); //5초 이후에 자기 자신에게 SIGALRM을 발생시킨다. -> my_alrm_handler가 캐치
	while (1) {
		printf ("Hello\n");
		sleep (2);
	}
}