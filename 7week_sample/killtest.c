#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int main (int argc, char *argv[]) //파라미터 썼다 (시그널 쓸거라)
{
	int pid, sig_num, result;
	if (argc != 3) { 
		printf ("Needs pid signum\n");
		exit(0); //프로그램 어디서든지 종료 가능. 0이면 정상 종료
	}
	pid = atoi (argv[1]); //문자열을 정수로 바꿔주는게 atoi
	sig_num = atoi (argv[2]);
	result = kill (pid, sig_num); //파라미터 순서 보기, 이해하기.
	printf ("result = %d\n", result);
}

/*
system call : kill

kill로 signal을 보낼 수 있다.
이거 테스트 하려면 프로그램 또 필요하다.


ps -aus | grep a.out : 프로세서 아이디 알 수 있다.
현재 실행중인거 출력 a.out


./killtest 1026 9 : 프로세서 아이디가 1026. 얘한테 9번 시그널을 보낸 것
result 값이 0 나오면 정상적인 종료가 (kill) 일어난것임.
권한이 있어야 한다.
내 프로세서, 내 kill signal 이어야 한다.
루트가 프로세서 주인, 내가 kill signal을 보내면 : 실패. (권한이 없기 때문에 반응이 없다.)
반대로 내가 프로세서 주인, 루트가 kill signal을 보내면 : 된다. (루트는 최고 권위자. 권한이 있다.)


*/
/*

sleep에 대한 언급
쉬었다가 이어서 일을 하는 거
쉬는 중에 인터럽트가 발생하면(시그널) 바로 깨어남
그래서 바로 시그널 핸들링 해줌 (7초 다 기다리는거 아니고 바로)

signal 중에는 SIGUSR1, 2는 내가 정해서 쓰는거다
SIGALRM 도 관심이 있다.
*/
