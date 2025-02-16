#include <stdio.h>
#include <string.h>
#include <unistd.h>

FILE *input, *output;

int main(int argc, char** argv){
	int i=0;
	if(argc > 3){
		printf("usage: %s [INPUT_FILE] [OUTPUT_FILE_NAME]\n",argv[0]);
		return -1;}
	if(argc == 3){
		if(!strcmp(argv[1], argv[2])){
			printf("Output file cannot be the same as input file\n");
			return -2;}
		input = fopen(argv[1], "r+");
		output = fopen(argv[2], "w+");
	}
	if(argc == 2){
		if(!strcmp(argv[1],"-h")){
			execlp("less", "less", "spec", (char *)NULL);
			//this is meant to only execute if less fails
			FILE * spec;
			spec = fopen("spec", "r");
			if (spec == NULL) {
				printf("usage: %s [INPUT_FILE] [OUTPUT_FILE_NAME]\n",argv[0]);
				return -16;}
			int c;
		    while ((c = fgetc(spec)) != EOF) {
        		printf("%c", c);
    		}
			fclose(spec);
			return 0;
		}

	}

	printf("\n");

	return 0;
}

