#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
int exist (char* filename)
{	int existed = FALSE;
	FILE* f=fopen(filename,"r");
	if (f!=NULL){
		existed=TRUE;
		fclose(f);
	}
	return existed;
}
int writefile(char* filename){
	char line[201];
	int length=0;
	if(exist(filename)==TRUE){
		printf("The file %s existed. Override it Y/N?:", filename);
		if(toupper(getchar())=='N'){
			return FALSE;
		}
	}
	FILE* f=fopen(filename,"w");
	printf("Type in the text data:\n");
	fflush(stdin);
	do{	
		gets(line);
		length=strlen(line);
		if(length>0){
			fputs(line,f);
			fputs("\n",f);
		}
	}
	while(length>0);
	fclose(f);
	return TRUE;
}
int printfile(char* filename){
	char c;
	if(exist(filename)==FALSE){
		printf("The file %s does not exist.\n",filename);
		return FALSE;
	}
	FILE* f=fopen(filename,"r");
	while ((c=fgetc(f))!=EOF){
		putchar(c);
	}
	fclose(f);
	return TRUE;
}
int main (int argCount, char* args[]){
	char filename[81];
	printf("Program for writing then reading a file\n");
	printf("Enter a filename:");
	gets(filename);
	printf("Write file:\n");
	if(writefile(filename)==TRUE){
		printf("Data in the file %s:\n", filename);
		if(printfile(filename)==0){printf("File error!\n");
		}
	}
	else{printf("Can not write the file %s\n", filename);
	}
	getchar();
	return 0;
}
