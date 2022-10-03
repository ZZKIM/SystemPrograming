#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct student{
	int num1;
	int num2;
	int num3;
};
int main(void){
	
	struct student s;
	
	int fd;
	fd = open ("temp.txt", O_RDWR | O_CREAT);
	
	int i = 0;
	while(i++<5){
	read (fd, &s, sizeof(struct student));
	printf("%d %d %d\n", s.num1, s.num2, s.num3);
	}
	
	close (fd);	

	return 0;
}

