/*(1) 실습 1

   - 5초에 한번씩 자신의 이름과 현재 시각을 출력

   - 3회 후에 프로그램 종료

   - alarm (), SIGALRM 핸들러 사용 : 메인에서 하면 안됨.

    메인은 1초에 한번씩 hello 찍고
*/

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <time.h>

int cnt;

void my_alarm_handler (int signum)
{
    cnt++;


	printf ("김가희 \n");

    time_t ct; //초 
	struct tm tm; //초를 변환할 수 있는 구조체
	ct = time (NULL); //현재 시간 얻어 옴
	tm = *localtime (&ct); //바꿔줌
	printf ("%d-%d-%d hour: %d, min : %d, sec: %d\n",
		tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, 
		tm.tm_min, tm.tm_sec);

	//printf ("Signal is caught. \n");
    if(cnt ==3)
        exit(0);
	alarm (5); //응용 버전 : 이거 또 만나면 또 5초 후에 시그널 발생 : 즉 결국에는 5초마다 printf가 발생한다.
    //5초에 한번씩 이벤트가 있다 근데 원래 할일도 있다 라고 하면 이런식으로 프로그램을 짜면 된다. (sleep은 멈춰있는건데 얘는 아니니까.)
}
int main ()
{

	signal (SIGALRM, my_alarm_handler); //함수 호출 아님.
	alarm (5); //5초 이후에 자기 자신에게 SIGALRM을 발생시킨다. -> my_alrm_handler가 캐치
	while (1) {
		printf ("Hello\n");
		sleep (1);
	}
}