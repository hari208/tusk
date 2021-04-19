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
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void main()
{
	int srvfd;
	int ret,ret1;
	char buf[15];
	ret1=mkfifo("srvfifo",0666);
//	printf("ret1=%d\n",ret1);
	srvfd=open("srvfifo",O_RDONLY);
//	printf("open ret=%d\n",srvfd);
	ret=read(srvfd,buf,15);
	buf[ret]='\0';
	printf("srever receives:%s\n",buf);
}
