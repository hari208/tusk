#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void main()
{
	int clifd;
	int ret;
	char buf[15];
	clifd=open("srvfifo",O_WRONLY);
//	printf("open returns=%d\n",clifd);
	printf("enter the string:");
	scanf("%s",buf);
	write(clifd,buf,strlen(buf));
	printf("clint send:%s\n",buf);
}
