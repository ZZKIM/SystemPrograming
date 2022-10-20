//kill test를 위한 . CPU 잡아먹으면서 무한루프 도는 거임.
#include <stdio.h>

int main(){


    while(1) {
        printf("Hello\n");
        sleep(2);
    }

    return 0;
}