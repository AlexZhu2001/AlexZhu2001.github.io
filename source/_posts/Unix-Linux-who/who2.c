/* 
 * who version2 
 * show who login this machine
 * change time format
 * delete useless one
 *
 *          open utmp file
 *     +--->read record-----<is eof>-----+
 *     |    print record--<is empty>--+  |                                
 *     |                              |  |
 *     +------------------------------+  |  
 *                                       |
 *          close utmp file<-------------+
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <string.h>

#define SHOW_HOSTS

void show_info(struct utmp *utmpbuf);
void show_time(time_t time);
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
    if(strlen(utmpbuf->ut_name)==0) return;
	printf("%-8.8s",utmpbuf->ut_name);
	printf(" ");
	printf("%-8.8s",utmpbuf->ut_line);
	printf(" ");
	//printf("%10ld",(long)utmpbuf->ut_time);
	show_time(utmpbuf->ut_time);
    printf(" ");
#ifdef SHOW_HOSTS
	printf("(%s)",utmpbuf->ut_host);
#endif
	printf("\n");
}

void show_time(time_t time){
    char *str=ctime(&time);
    printf("%12.12s",str+4);
}
