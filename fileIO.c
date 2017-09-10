#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define CREATE_RW_R_R (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
#define OPEN_RW_APPEND (O_RDWR|O_CREAT|O_APPEND)
#define OPEN_RW_TRUNC (O_RDWR|O_CREAT|O_TRUNC)

int main(void)
{
	char buf1[] = "abcdef";
	char buf2[1024];
	int fd;
	int size;
	off_t offset = 3;
	fd = open("file", OPEN_RW_TRUNC, CREATE_RW_R_R);
	printf("fd: %d\n", fd);
	size = write(fd, buf1, 6);
	printf("write bufer '%s', bufer size: %d\n", buf1, size);
	close(fd);
	fd = open("file", O_RDWR);
	printf("fd: %d\n", fd);
	offset = lseek(fd, offset, SEEK_CUR);
	printf("offset: %lld\n", offset);
	size = read(fd, buf2, 1024);
	printf("read bufer size: %d\n", size);
	printf("read bufer: %s\n", buf2);
	close(fd);
}
