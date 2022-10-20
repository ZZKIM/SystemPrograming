//signal이 발생하면 캐치를 해서 잠시 핸들링을 해서 . 그 다음에는 자기자신 다른거 할일 한다.

//kill test를 위한 . CPU 잡아먹으면서 무한루프 도는 거임.
#include <stdio.h>
#include <signal.h>
void my_sig_handler(int signum){

    printf("signal number = %d", signum);
    printf("Signal is caught.\n");

    if(signum == SIGINT){
        //signal(SIGINT, SIG_IGN);
        signal(SIGINT, SIG_DFL);
    }
}
int main(){

    signal(SIGINT, my_sig_handler);

    while(1) {
        printf("Hello\n");
        pause(); //더이상 진행이 안됨 (멈춰있는다.). 새로운 시그널 발생할 때 까지 아무것도 안함.
        //sleep(2);
    }

    return 0;
}

/*
컨트롤 2 누르면 2번 시그널 보내지기 때문에 pause가 깨어나서 또 일을 한다.
*/
int main(){

    signal(SIGINT, SIG_IGN);
    signal(SIGUSR1, my_sig_handler); //특정 시그널을 위한 시그널
    signal(SIGUSR2, my_sig_handler);

    while(1) {
        printf("Hello\n");
        pause(); //더이상 진행이 안됨 (멈춰있는다.). 새로운 시그널 발생할 때 까지 아무것도 안함.
        //sleep(2);
    }

    return 0;
}
/*
함수포인터가 시그널을
SIG_IGN : ignore 무시하라고 하는 처리. : 아무런 핸들링을 하지 않는다. : 특별한 함수 포인터
default는 죽이는 거다.
SIG_DFL : 디폴트 핸들러를 사용하라라고 하는 명령 : 내가 정의한거 말고 시스템 상에서의 디폴트 액션 : 죽임

만약에 처음 C 2 하면 일단 내가 짠걸로 핸들링을하고 거기 안에서 signal(SIGINT, SIG_DFL) 이라고 했기 때문에
그 다음부터는 디폴트로 된다. : C 2 또 하면 죽는다.

signal 이라는 의미는 앞으로 이게 발생하면 글케 해라라는거지 함수 호출이 아니다.

SIGINT 발생하면 : 그 시점에서 잠시 멈추고 캐치해서 시그널 핸들러 호출이 된다. : 시그널 처리 : 다 끝나면 다시 돌아와서 하던일(멈춘 시점) 마저 한다.
버그 있을 수 있다 : 예를 들어서 전역변수가 시그널핸들러에서 값이 변하면 : 버그
race condition 이라고 한다.
시그널 명령어도 시간이 필요 : 시그널 핸들러에서 도중에 시그널이 발생 : 또 멈추고 돌아오냐? 아님. 중간에 발생한거 처리 안하고 발생 유무만 비트로 기억한다.
나중에 그거 보고 (기존의 시그널 핸들러 일을 끝낸 후) 아 또 발생했구나 몇번이 발생했구나 하고 또 시그널 핸들러 호출한다. 발생했다만 기억 (10번 발생해도 : 발생했다! 일케 기억)

SIG_IGN : signal(SIGKILL, SIG_IGN); 이렇게도 사용 가능하다.
SIGKILL 같은거는 IGN하더라도 사용할 수 있다. -9
*/