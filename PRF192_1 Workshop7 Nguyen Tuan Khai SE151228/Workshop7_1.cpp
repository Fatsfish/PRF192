#include <stdio.h>
#include<string.h>
#include<conio.h>
int menu(){
printf("\n");
	printf("\n1- Add a Student");
	printf("\n2- Remove a student");
	printf("\n3- Search a student");
	printf("\n4- Print out the list in ascending order");
	printf("\n5- Quit");
	printf("\nSelect:");
	int choice;
	scanf("%d%*c", &choice);
	return choice;
}
char* rTrim (char s[])
{	
	int i= strlen(s)-1;
	while (s[i]==' '){i--;}
	s[i+1]= '\0';
	return s;}
char* lTrim (char s[])
{
	int i=0;
	while (s[i]==' '){i++;}
	if(i>0){strcpy(&s[0], &s[i]);}
	return s;}
char* trim (char s[]){
	rTrim(lTrim(s));
	char *ptr=strstr(s,"  ");
	while(ptr!=NULL){
		strcpy(ptr,ptr+1);
		ptr = strstr(s, "  ");
	}
	return s;
}
void addname(char name[31], char names[100][31], int &n){
	if (n==100){printf("The list is full!\n");}
	else{
		strcpy(names[n],name);
		n++;
		printf("The name is added.\n");
	}
}
void print(char names[][31], int a){
	int i;
	for(i=0;i<a;i++){
		printf("The position %d has the name: ", (i+1));
		puts(names[i]);
	}
}
int search(char name[31],char names[100][31], int n){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(name, names[i])==0){return i;}
	}
	return -1;
}
void remove(int pos, char names[100][31], int &n){
	if(pos>=0 && pos<n){
		for(int i=pos;i<n-1;i++){strcpy(names[i],names[i+1]);}
		n--;
	}
}
void Asce(char names[100][31],int n){
	int i,j;
	char t[31];
	for (i=0;i<n-1;i++){
		for(j=n-1;j>0;j--){
			if(strcmp(names[j],names[j-1])<0){
				strcpy(t,names[j]);
				strcpy(names[j],names[j-1]);
				strcpy(names[j-1],t);}}}}
int main(){
	char names[100][31];
	int n=0;
	char name[31];
	int choice;
	int pos;
	do{
		choice=menu();
		switch(choice){
			case 1:
					printf("Enter a new name:");
					do{
						fflush(stdin);
						gets(name);
					}
					while (strlen(name)==0);
					strupr(trim(name));
					addname(name,names,n);
					break;
			case 2:
					printf("Enter a wish name to be removed:");
					fflush(stdin);
					gets(name);
					strupr(trim(name));
					pos = search(name, names, n);
					if(pos<0){puts("\n This name doesn't exist!\n");}
					else{
						remove(pos, names,n);
						puts("\nThe name is removed.\n");
					}
					break;
			case 3:
					printf("Type in a searched name:");
					fflush(stdin);
					gets(name);
					strupr(trim(name));
					pos= search(name,names,n);
					if(pos<0){puts("\n This name doesn't exist!\n");}
					else{ printf("\nPosition is found:%d\n",pos+1);}
					break;
			case 4:
					if(n==0){puts("\nEmpty list\n");}
					else{
					print(names,n);
					printf("The names after being aranged:\n");
					Asce(names,n);
					print(names,n);
					}
					break;
			default: 
					if(choice<0 || choice>5){printf("The option is not supported.\n");}
					if(choice==5){printf("Goodbye!\n");}
					printf("Have a nice day!");	
		}
	}
	while(choice>0 &&choice<5);
	getchar();
	return 0;
}

