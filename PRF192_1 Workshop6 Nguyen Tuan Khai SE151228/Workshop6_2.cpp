#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
int menu(){
printf("\nOne-Dimensional Array of Intergers");
	printf("\n1- Add a Value");
	printf("\n2- Search a Value");
	printf("\n3- Print out the array");
	printf("\n4- Print out values in range");
	printf("\n5- Print out the array in ascending order");
	printf("\nOthers- Quit");
	printf("\nSelect:");
	int choice;
	scanf("%d", &choice);
	return choice;
}
int intRandom(int min, int max)
{ 	
int value;
	value=min+rand()%(max-min);	
}
int isFull (int *a, int n){
	return n==MAXN;
}
int isEmpty (int *a, int n){
	return n==0;
}
void add( int value, int *a, int *pn){
	a[*pn]=value;
	(*pn)++;
}
int search(int z,int *a, int n){
	int i;
	for(i=0;i<n;i++){if(a[i]==z){return i;}}
	return -1;
	}
void print(int *a, int n){
		if(isEmpty(a,n)){printf("\nSorry! The array is empty.\n");
			}
	int i;
	for(i=0;i<n;i++){printf("%d\n", a[i]);
	}
}
void printRange(int*a, int n){
	int i;
	int x;
	int y;
		if(isEmpty(a,n)){printf("\nSorry! The array is empty.\n");
			}
			else{
	printf("Type 2 ends of the range:");
	fflush(stdin);
	scanf("%d %d", &x, &y);
	if(x>=y){
			for(i=0;i<n;i++){
		if(a[i]<=x && a[i]>=y){printf("%d\n", a[i]);}
		}}
	if(x<=y){	for(i=0;i<n;i++){
		if(a[i]>=x && a[i]<=y){printf("%d\n", a[i]);}
		}}
		else{printf("There's no value!");}}
}
void printAsc(int *a,int n){
	if(isEmpty(a,n)){printf("\nSorry! The array is empty.\n");
			}
	int** adds=(int**)calloc(n,sizeof(int*));
	int i,j;
	for(i-0;i<n;i++){adds[i]= &a[i];
	}
	int* t;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(*adds[j]<*adds[j-1]){
				t=adds[j];
				adds[j]=adds[j-1];
				adds[j-1]=t;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d", *adds[i]);
	}
	free(adds);
}
int main(){
	int a[MAXN];
	int n=0;
	int value;
	int userChoice;
	do{
		userChoice= menu();
		switch (userChoice)
		{ case 1:
			if(isFull(a,n)){printf("\nSorry! The array is full.\n");
			}
			else{printf("Input an added value:");
			scanf("%d", &value);
			add(value,a,&n);
			printf("added\n");
			}
			break;
		case 2:
			if(isEmpty(a,n)){printf("\nSorry! The array is empty.\n");
			}
			else{printf("Input the searched value:");
			scanf("%d", &value);
			int pos= search(value,a,n);
			if(pos<0){printf("Not found!\n");
			}else{
			printf("Position is found:%d\n", pos);
			}}
			break;
		case 3: print (a,n);
		break;
		case 4: printRange(a,n);
		break;
		case 5:	printAsc(a,n);
		break;
		default: printf("\nGoodbye.\n");
	}
}
while (userChoice>0 && userChoice<5);
getchar();
return 0;}
