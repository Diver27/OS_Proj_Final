#include "stdio.h"

int currentTime();

int main(int argc, char * argv[])
{
	if(argc<=1){
		printf("Hello World!\n");
	}
	else{
	int i;
	for (i = 1; i < argc; i++)
		printf("%s%s", i == 1 ? "" : " ", argv[i]);
	printf("\n");
	}
	return 0;
}


