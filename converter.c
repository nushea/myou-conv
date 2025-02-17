#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define BUFFER 0x20

char LeftDecorator[] = ">-#";

FILE *input, *output;
int base = 10;

int readChar(char *c){ //{{{
	*c = fgetc(input);
	if(*c == EOF)
		return 0;
	return *c;
} //}}}

int ChangeBase(){ //{{{
	char c, deco[BUFFER];
	memset(deco, 0, BUFFER);
	deco[0]=LeftDecorator[0];

//	fputc(LeftDecorator[0], output);
	int p = 1, ChangedBase = 0;
	while(readChar(&c) == LeftDecorator[p] && p < strlen(LeftDecorator)){
		deco[p] = c;
//		fputc(c, output);
		p++;}
	if(p==strlen(LeftDecorator) && c>='0' && c<='9'){
		ChangedBase = 1;
		base = 0;
		if(strlen(LeftDecorator)>1)
			fprintf(output, "%s", LeftDecorator+1);
		fputc(c, output);
		while(c >= '0' && c <= '9'){
			base = base*10+ c - '0';
			readChar(&c);
			fputc(c, output);
		}
//		printf("Base: %i\n",base);
	}
	else{
		fprintf(output, "%s", deco);
		fputc(c, output);
	}

	return 0;
} //}}}

int isTempBase(char c){ // {{{
//	printf("%c ", c);
	switch(c){
		case 'b': return 2;
		case 't': return 3;
		case 'q': return 4;
		case 's': return 6;
		case 'o': return 8;
		case 'i': return 10;
		case 'd': return 12;
		case 'x': return 16;
		case 'm': return 32;
	}
	return 0;
} //}}}

int ConvertNumber(char * input, char * output, int base){
	int decinumber=0, i=0;
	while(input[i]){
		if(input[i]<='9')
			decinumber = decinumber*base + input[i] - '0';
		else
			decinumber = decinumber*base + input[i] - 'A' + 10;
		i++;
	}
	if(!decinumber){
		strcpy(output, "0");
		return 0;
	}
//	printf(" or %i (", decinumber);
	i = ceil(log(decinumber)/log(10))-1;
//	printf("%i) ", i);
	while(i>=0){
		output[i]=decinumber%10 + '0';
		i-=1;
		decinumber/=10;
	}
//	printf(" or %s\n", output);
	return decinumber;
}

void InpOup(){
	char c;
    while (readChar(&c)) {
		if(c == LeftDecorator[0]){
			ChangeBase();				
			continue;
		}
		if(c >= '0' && c <= '9'){
			char numberS[BUFFER];
			memset(numberS, 0, BUFFER);
			numberS[0] = c;
			int p = 0;
			while(numberS[p]){
				if((numberS[p] > '9' && numberS[p] < 'A') || numberS[p] < '0' || numberS[p] > 'Z')
					break;
//				printf("%c", numberS[p]);
				p++;
				readChar(&numberS[p]);
			}
			c = numberS[p];
			numberS[p] = '\0';
//			printf("%s", numberS);
			char oup[BUFFER];
			memset(oup, 0, BUFFER);
			if(isTempBase(c)){
				ConvertNumber(numberS, oup, isTempBase(c));
			}else
				ConvertNumber(numberS, oup, base);
			for(int i=0;i<strlen(oup);i++)
				fputc(oup[i], output);
			if(!isTempBase(c))
				fputc(c, output);
			
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

