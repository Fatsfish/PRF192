#include<stdio.h>
#include<ctype.h>
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
	char c;
	int CTRL_Z=-1;
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
		c=getchar();
		if(c!=CTRL_Z){
			fputc(c,f);
		}
	}
	while(c!=CTRL_Z);
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
	if(argCount!=2){
		printf("Syntax: workshop8_1 filename\n");
	}
	else if(writefile(args[1])==TRUE){
		printf("Writing the file %s: done\n", args[1]);
	}
	else{printf("Can not write the file %s\n", args[1]);
	}
	printfile(args[1]);
	return 0;
}
