#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER 0x20

char LeftDecorator[] = ">-#";
char RightDecorator[] = "#-<";

FILE *input, *output;
int base = 10;

int readChar(char *c){ //{{{
	*c = fgetc(input);
	if(*c == EOF)
		return 0;
	return *c;
} //}}}

void InpOup(){
	char c;
    while (readChar(&c)) {
		if(c == LeftDecorator[0]){
			fputc(c, output);
			int p = 1;
			while(readChar(&c) == LeftDecorator[p] && p < strlen(LeftDecorator)){
				fputc(c, output);
				p++;}
			fputc(c, output);
			if(p==strlen(LeftDecorator)) 
				printf("uwu ");
			p = 0;
			continue;
		}
		fputc(c, output);
	}
}

int main(int argc, char** argv){

	//{{{ Initial checks
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
		input = fopen(argv[1], "r+");
	} //}}}
	// {{{ open input and output files
	if(input == NULL){
		char inputFileName[BUFFER];
		printf("INPUT FILE NAME = ");
		scanf("%s", inputFileName);
		input = fopen(inputFileName, "r+");
	}
	if(output == NULL){
		char outputFileName[BUFFER];
		printf("OUTPUT FILE NAME = ");
		scanf("%s", outputFileName);
		output = fopen(outputFileName, "r+");
	} // }}}

	InpOup();

	fclose(input);
	fclose(output);
	return 0;
}

