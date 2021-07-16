#include <stdio.h>
#include<string.h>
#include<conio.h>
int menu(){
printf("\n");
	printf("\n1- Add a new employee");
	printf("\n2- Search employees by name");
	printf("\n3- Remove employee by code");
	printf("\n4- Print out the list in descending order by salary and allowance");
	printf("\nOthers- Quit");
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
void addname(char codes[][9], char names[100][31], double salaries[], double allowances[], int &n){
	char code[9], name[31];
	double salary, allowance;
	if (n==100){printf("The list is full!\n");}
	else{
		printf("\nEnter data of new employee:\n");
		printf("Employee code:");
		fflush(stdin);
		scanf("%8s", code);
		strupr(trim(code));
		printf("Employee name:");
		fflush(stdin);
		scanf("%30[^\n]", name);
		strupr(trim(name));
		printf("Salary:");
		scanf("%lf", &salary);
		printf("Allowance:");
		scanf("%lf", &allowance);
		strcpy(codes[n],code);
		strcpy(names[n],name);
		salaries[n]=salary;
		allowances[n]=allowance;
		n++;
		puts("\nNew employee has been added.\n");
	}
}
void print(char codes[][9], char names[][31],double salaries[], double allowances[], int n){
	printf("\nEmployee list:\n");
	int i;
	for(i=0;i<n;i++){
		printf("%9s, %31s, %.21f, %.21f\n", codes[i],names[i], salaries[i], allowances[i]);
	}
}
int search (char name[], char names[][31], int n){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(name, names[i])==0){return i;}
	}
	return -1;
}
int searchName(char codes[][9],char names[100][31], double salaries[], double allowances[], int &n){
	char name[31];
	if(n==0){printf("The list is empty.\n");
	}
	else{
		int i, pos;
		printf("Enter a name for searching:");
		fflush(stdin);
		gets(name);
		strupr(trim(name));
		for(i=0;i<n;i++){
			if(strcmp(name, names[i])==0){
				printf("%s, %s, %.21f, %.21f\n", codes[i], names[i], salaries[i], allowances[i]);
			}
		}
		pos=search(name,names,n);
		if(pos<0){printf("The name doesn't exist!");}
	}
}
int searchCode (char code[], char codes[][9], int n){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(code, codes[i])==0){return i;}
	}
	return -1;
}
void remove(int pos, char codes[][9], char names[100][31], double salaries[], double allowances[], int &n){
	if(pos>=0 && pos<n){
		for(int i=pos;i<n-1;i++){
			strcpy(codes[i],codes[i+1]);
			strcpy(names[i],names[i+1]);
			salaries[i]=salaries[i+1];
			allowances[i]=allowances[i+1];
		}
		n--;
	}
}
void Desc(char codes[][9], char names[100][31],double salaries[], double allowances[], int n){
	char code[9], name[31];
	double t;
	int i,j;
	for (i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			double d1= salaries[j]+allowances[j];
			double d2= salaries[j-1]+allowances[j-1];
			if(d1>d2){
				strcpy(name,names[j]);
				strcpy(names[j],names[j-1]);
				strcpy(names[j-1],name);
				
				strcpy(code,codes[j]);
				strcpy(codes[j],codes[j-1]);
				strcpy(codes[j-1],code);
				
				t=salaries[j];
				salaries[j]=salaries[j-1];
				salaries[j-1]=t;
				
				t=allowances[j];
				allowances[j]=allowances[j-1];
				allowances[j-1]=t;
			}
		}
	}
}			
int main(){
	char names[100][31], codes[100][9];
	double salaries[100], allowances[100];
	int n=0;
	int choice;
	int pos;
	do{
		choice=menu();
		switch(choice){
			case 1:
					addname(codes,names, salaries, allowances,n);
					break;
			case 2:
					searchName(codes, names, salaries, allowances, n);
					break;
			case 3:
					if(n==0){printf("The list is empty");
					}
					else{
						char code[9];
						printf("Type in a removed code:");
						fflush(stdin);
						gets(code);
						strupr(trim(code));
						pos= searchCode(code,codes,n);
						if(pos<0){puts("\n This name doesn't exist!\n");}
						else{ printf("\nPosition is found:%d\n",pos+1);
						remove(pos, codes, names, salaries, allowances,n);
						puts("\nThe employee is removed.\n");}
					}
					break;
			case 4:
					if(n==0){puts("\nEmpty list\n");}
					else{
					print(codes, names, salaries, allowances, n);
					printf("The names after being aranged:\n");
					Desc(codes, names, salaries, allowances, n);
					print(codes, names, salaries, allowances, n);
					}
					break;
			default: 
					printf("Goodbye. Have a nice day!");	
		}
	}
	while(choice>0 &&choice<5);
	getchar();
	return 0;
}

