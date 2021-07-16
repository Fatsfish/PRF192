#include <stdio.h>
#include<string.h>
#include<conio.h>
int menu(){
printf("\nOne-Dimensional Array of Intergers");
	printf("\n1- Add a Student");
	printf("\n2- Remove a student");
	printf("\n3- Search a student");
	printf("\n4- Print out the list in ascending order");
	printf("\n5- Quit");
	printf("\nSelect:");
	int choice;
	scanf("%d", &choice);
	return choice;
}
int isFull (char names[100][31], int n){
	return n==99;
}
int isEmpty (char names[100][31], int n){
	return n==0;
}
void addname(char names[][31], int n)
{
	int i;
	for (i=0;i<4;i++){
		printf("Type in a name at %d/%d:", i+1,n);
		fflush(stdin);
		scanf("%31[^\n]",names[i]);
		strupr(names[i]);}
}
void add( char value, char names[][31], int *pn){
	names[*pn][31]=value;
	(*pn)++;
}
void Asce(char names[][31],int n){
	int i,j;
	char t[31];
	for (i=0;i<n-1;j--){
		for(j=n-1;j>i;j--){
			if(strcmp(names[j],names[j-1])<0){
				strcpy(t,names[j]);
				strcpy(names[j],names[j-1]);
				strcpy(names[j-1],t);}}}}
void findName(char names[][31],int n){
	int i,j,d;
	char t[31];
	printf("Type the searched name:");
	fflush(stdin);
	scanf("%31[^\n]", &t);
	strupr(t);
	for (int i=0;i<n-1;i--){	
		if(names[i]==t){
			printf("%c is in the array", names);
			printf("The name is found at %d position\n", i+1);
		}}
	printf("The name is wrong or doesn't exist!\n");	
	if(names[i]==t){
		printf("Do you want to delete it?\n");
		printf("Type in 1 as yes and 0 as no");
		scanf("%d", &d);
		if(d==1){
			names[i][31]=names[i+1][31];
			printf("The name has been deleted!\n");
		}
		else{printf("Have a good day!");
		}
	}
	}
int removeOne (int pos, char names[][31], int*pn){
	if (pos<0|| pos>=*pn) return 0;
	int i;
	for (i=pos;i<*pn-1;i++){
		names[i][31]=names[i+1][31];}
	(*pn)--;
	return 1;
}
int main(){
	char b[31];
	char names[100][31];
	int n=100;
	int userChoice;
	char t;
	do{
		userChoice= menu();
		switch (userChoice)
		{ 
			case 1:
					if(isFull(names,n)){printf("\nSorry! The list is full.\n");
					}
					else{
					fflush(stdin);
					scanf("%31[^\n]", &names);
					addname(names,n);
					printf("added\n");
					}
			break;
			case 2:	
					int pos;
					if(isEmpty(names,n)){printf("\nSorry! The list is empty.\n");
					}
					findName(names,n);
			break;
			case 3: findName(names,n);
			break;
			case 4: Asce(names,n);
			break;
			case 5:	printf("\nGoodbye. Have a nice day!\n");
			break;
			default: printf("\nThe option is not supported! Have a nice day!\n");
		}
}
while (userChoice>0 && userChoice<6);
getchar();
return 0;}

	

