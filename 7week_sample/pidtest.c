#include <stdio.h>
#include <sys/types.h>

int main ()
{

    pid_t pid;
	pid = getpid (); //자기 pid 얻어올 수 있음. 프로그램내에서 pid 알고 싶을 때 사용한다.
	printf ("pid = %d \n", pid);
}