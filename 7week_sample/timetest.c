//현재 시간 출력하는거. 이거보다는 시그널이 더 중요한듯
#include <stdio.h>
#include <time.h>

int main ()
{
	time_t ct; //초 
	struct tm tm; //초를 변환할 수 있는 구조체
	ct = time (NULL); //현재 시간 얻어 옴
	tm = *localtime (&ct); //바꿔줌
	printf ("%d-%d-%d hour: %d, min : %d, sec: %d\n",
		tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, 
		tm.tm_min, tm.tm_sec);

}
/*
암튼 이런 방법도 있다.
현재시각을 출력한다.
year에 1900을 더하고
month에 1을 더해야
우리가 아는 시간이 나온다.
*/