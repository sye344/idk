#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
int main(int argc, char* arg[]){
	char* token=arg[0];
	if(token==NULL || strcmp(token,"-R")==0){
		time_t t;
		time(&t);
		if(t==-1){
			printf("time function failed \n");
		}
		printf("%s\n",ctime(&t));
	}
	else if(strcmp(token,"-u")==0){		
		time_t t=time(&t);
		struct tm *utc=gmtime(&t);
		if(utc==NULL){
			printf("Gmtime function failed \n");
		}
		printf("UTC TIME : %s\n",asctime(utc));
	}
	else{
		printf("Command not supported\n");
	}
}