#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXN 100
int menu(){
	printf("\nAssignment Menu:");
	printf("\n1- Print a random number between 1-20 array");
	printf("\n2- Search a Value and the times it is repeated");
	printf("\n3- Search a Value and delete the first appear value");
	printf("\n4- Add a Value in position");
	printf("\n5- Print out the array in ascending order");
	printf("\n6- Print out the array in decending order");
	printf("\n7- Add a name");
	printf("\nOthers- Quit");
	printf("\nSelect:");
	int choice;
	scanf("%d", &choice);
	return choice;
}
int intRandom(int min, int max)
{ 	return min+rand()%(max-min);	
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
	for(i=0;i<n;i++){if(a[i]==z){
	return i;}
	}
	return -1;
}
int subsearch(int z,int *a, int n){
	int i, count;
	for(i=0;i<n;i++){if(a[i]==z){
	count=1;
	count++;
	return count;}
	}
	}
int removeOne (int pos, int*a, int*pn){
	if (pos<0|| pos>=*pn) return 0;
	int i;
	for (i=pos;i<*pn-1;i++){
		a[i]=a[i+1];}
	(*pn)--;
	return 1;
}
void printAsc(int *a,int n){
	if(isEmpty(a,n)){printf("\nSorry! The array is empty.\n");}
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
void printDesc(int*a, int n)
{
		if(isEmpty(a,n)){printf("\nSorry! The array is empty.\n");
			}
	int**adds=(int**)calloc(n,sizeof(int*));
	int i,j;
	for(i=0;i<n;i++){adds[i]=&a[i];}
	int*t;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(*adds[j]>*adds[j-i]){
				t=adds[j];
				adds[j]=adds[j-i];
				adds[j-1]=t;
			}
		}
	}
	for(i=0;i<n;i++){printf("%d", *adds[i]);}
	free (adds);
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
char* nameStr(char s[]){
	trim(s);
	strupr(s);
	printf("\nThe uppercase name is:");
	printf(s);}
void seperate( int value, char *a, char *pn){
	a[*pn]=value;
	(*pn)++;}
void Reverse(char *s){
	strupr(s);
	char *t;
	int i;
	for(i=0;i<=strlen(s)-1;i++)	
	if( s[i]==' '&& s[i-1]!=' ')
	break;
	t=s+i+1;
	s[i]='\0';
	printf("\nHo lot: ");
	puts(s);
	printf("\nTen: ");
	puts(t);
	char k;
	k=strlen(t);
	seperate(',',t,&k);
	strcat(t,s);
	printf("\nThe name after being changed:");
	printf(t);}
int main(){
	int a[MAXN];
	int n=0;
	int value,v,i,count;
	int userChoice;
	char s[50];
	char *t;
	do{
		userChoice= menu();
		switch (userChoice)
		{
		case 1:
				printf("Type in the number of random variables in the array:");
				fflush(stdin);
				scanf("%d", &v);
				srand(time(NULL));
				for(i=0;i<v;i++){
					a[i]=intRandom(1,20);
					add(a[i],a,&n);
			   		printf("The random numbers array between 1 and 20 are: %d\n", a[i]);}			
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
			int count=subsearch(value,a,n);
			printf("The number it appears:%d\n", count);
			}}
			break;
		case 3:{
			if(isEmpty(a,n)){printf("\nSorry! The array is empty.\n");
			}
			else{printf("Input the searched value:");
			scanf("%d", &value);
			int pos= search(value,a,n);
			if(pos<0){printf("Not found!\n");
			}else{
			printf("Position is found:%d\n", pos);
			removeOne(pos,a,&n);
			printf("The First appear value has been deleted\n");
			}
			break;}
		case 4:{
			int pos;
			if(isFull(a,n)){printf("\nSorry! The array is full.\n");}
			else{printf("Input an added value:");
			scanf("%d", &value);
			printf("Input the position of the value:");
			scanf("%d", &pos);
			add(value,a,&pos);
			printf("The value (%d) is added at position %d\n", value,pos);
			}
			break;}
		case 5:	printAsc(a,n);
			break;
		case 6: printDesc(a,n);
			break;
		case 7: 
			char s[50];
			char *t;
			printf("Type the added name:");
			fflush(stdin);
			scanf("%[^\n]", &s);
			nameStr(s);
			Reverse(s);
			getchar();
			break;
		default: printf("\nGoodbye.\n");
	}
}
}
while (userChoice>0 && userChoice<8);
printf("Have a nice day!");
getchar();
return 0;}
