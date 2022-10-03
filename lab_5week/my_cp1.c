#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
	
	int temp;
	int n=0, p= 0;
	int fd;
	fd = open ("src_file.txt", O_RDWR | O_CREAT);

	int fd1;
	fd1 = open ("dest_file.txt", O_RDWR | O_CREAT);

	while(1)
	{
	n = read (fd, &temp, sizeof(int));
	
	write (fd1, &temp, n);
		}

	close (fd);
	close (fd1);
	
	

	return 0;
}

