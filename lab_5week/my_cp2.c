#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct student{
	int num1;
	int num2;
	int num3;
};
int main(void){
	
	struct student s[5];

	//s[0] = {00, 01, 02};
	s[0].num1 =00;
	s[0].num2 =01;
	s[0].num3 =02;
	//s[1] = {10, 11, 12};
	s[1].num1 =10;
	s[1].num2 =11;
	s[1].num3 =12;
	
	//s[2] = {20, 21, 22};
	s[2].num1 =20;
	s[2].num2 =21;
	s[2].num3 =22;
	//s[3] = {30, 31, 32};
	s[3].num1 =30;
	s[3].num2 =31;
	s[3].num3 =32;
	//s[4] = {40, 41, 42};
	s[4].num1 =40;
	s[4].num2 =41;
	s[4].num3 =42;

	
	int fd;
	fd = open ("temp.txt", O_RDWR | O_CREAT);
	write (fd, &s[0], sizeof(struct student));
	write (fd, &s[1], sizeof(struct student));
	write (fd, &s[2], sizeof(struct student));
	write (fd, &s[3], sizeof(struct student));
	write (fd, &s[4], sizeof(struct student));
	
	close (fd);	

	return 0;
}

