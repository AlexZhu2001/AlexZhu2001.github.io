/* 
 * who version1 
 * show who login this machine
 */
#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOW_HOSTS

void show_info(struct utmp *utmpbuf);
int main(int argc,char *argv[]){
	struct utmp rec;
	int utmpfd;
	int reclen=sizeof(rec);
    utmpfd=open(_PATH_UTMP,O_RDONLY);
	if(utmpfd==-1){
		perror(_PATH_UTMP);
		exit(1);
	}
	while(read(utmpfd,&rec,reclen) == reclen){
		show_info(&rec);
	}
	close(utmpfd);
	return 0;
}

void show_info(struct utmp *utmpbuf){
	printf("%-8.8s",utmpbuf->ut_name);
	printf(" ");
	printf("%-8.8s",utmpbuf->ut_line);
	printf(" ");
	printf("%10ld",(long)utmpbuf->ut_time);
	printf(" ");
#ifdef SHOW_HOSTS
	printf("(%s)",utmpbuf->ut_host);
#endif
	printf("\n");
}
