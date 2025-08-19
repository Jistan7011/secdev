#include<stdio.h>
#include<stdint.h>


int main(int argc, char **argv){
	if(argc <2) {
		printf("at least more than one file\n");
		return 1;
	}

	for(int i=1; i<argc; ++i){
		const char *path=argv[i];
		FILE *f = fopen(path, "rb");
		if(!f) {perror(path); return 1;}


	}
}
