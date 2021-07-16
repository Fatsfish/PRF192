#include <stdio.h>
#include<string.h>
#include<conio.h>
int menu(){
printf("\n");
	printf("\n1- Add a new softdrink");
	printf("\n2- Search maker");
	printf("\n3- Search volume");
	printf("\n4- Print out the list in ascending order.");
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
void addname(char makes[][21], char names[100][21], int volumes[], int prices[], int durations[], int &n){
	char make[21], name[21];
	int volume, price, duration;
	if (n==100){printf("The list is full!\n");}
	else{
		printf("\nEnter data of new soft drink:\n");
		printf("Soft drink name:");
		fflush(stdin);
		scanf("%20[^\n]s", name);
		strupr(trim(name));
		printf("Soft drink make:");
		fflush(stdin);
		scanf("%20[^\n]", make);
		strupr(trim(make));
		printf("Volume:");
		scanf("%d", &volume);
		printf("Price:");
		scanf("%d", &price);
		printf("Duration:");
		scanf("%d", &duration);
		strcpy(makes[n],make);
		strcpy(names[n],name);
		volumes[n]=volume;
		prices[n]=price;
		durations[n]=duration;
		n++;
		puts("\nNew soft drink has been added.\n");
	}
}
void print(char makes[][21], char names[][21],int volumes[], int prices[],int durations[] ,int n){
	printf("\nSoft drink list:\n");
	int i;
	for(i=0;i<n;i++){
		printf("%21s, %21s, %21d, %21d, %21d \n",names[i], makes[i], volumes[i], prices[i], durations[i]);
	}
}
int searchchar(char name[], char names[][21], int n){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(name, names[i])==0){return i;}
	}
	return -1;
}
int searchnum(int volume, int volumes[], int n){
	int i;
	for(i=0;i<n;i++){
		if(volume==volumes[i]){return i;}
	}
	return -1;
}
int searchMake(char makes[][21],char names[100][21], int volumes[], int prices[],int durations[] ,int &n){
	if(n==0){printf("The list is empty");}
	else{
		char make[21];
		int i, pos;
		printf("Enter a name of maker for searching:");
		fflush(stdin);
		gets(make);
		strupr(trim(make));
		for(i=0;i<n;i++){
			if(strcmp(make, makes[i])==0){
				printf("%21s, %21s, %21d, %21d, %21d \n", makes[i], names[i], volumes[i], prices[i], durations[i]);
			}
		}
		pos=searchchar(make,makes,n);
		if(pos<0){printf("The soft drink doesn't exist!");}
	}
}
int searchVolume (char makes[][21],char names[][21], int volumes[],int prices[], int durations[], int n){
	if(n==0){puts("\nEmpty list\n");}
	else{
		int i,v1,v2,t,pos;
		printf("Enter the volumes for searching.\n");
		printf("Enter volume 1:");
		scanf("%d%*c", &v1);
		printf("Enter volume 2:");
		scanf("%d%*c", &v2);
		for(i=0;i<n;i++){
			if(v1>v2){t=v1;
			v1=v2;
			v2=t;
			}
			if(volumes[i]>=v1 && volumes[i]<=v2){
				printf("%21s, %21s, %21d, %21d, %21d \n", makes[i], names[i], volumes[i], prices[i], durations[i]);
			}
			else{printf("There's no soft drink fit the desire space!\n");
			break;
			}
		}
	}
}
void Asce(char makes[][21], char names[100][21],int volumes[], int prices[], int durations[],int n){
	char make[21], name[21];
	int t;
	int i,j;
	for (i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(volumes[j]<volumes[j-1]){
				strcpy(name,names[j]);
				strcpy(names[j],names[j-1]);
				strcpy(names[j-1],name);
				
				strcpy(make,makes[j]);
				strcpy(makes[j],makes[j-1]);
				strcpy(makes[j-1],make);
				
				t=volumes[j];
				volumes[j]=volumes[j-1];
				volumes[j-1]=t;
				
				t=prices[j];
				prices[j]=prices[j-1];
				prices[j-1]=t;
				
				t=durations[j];
				durations[j]=durations[j-1];
				durations[j-1]=t;}
			if(volumes[j]==volumes[j-1]){
				if(prices[j]<prices[j-1]){
					strcpy(name,names[j]);
					strcpy(names[j],names[j-1]);
					strcpy(names[j-1],name);
					
					strcpy(make,makes[j]);
					strcpy(makes[j],makes[j-1]);
					strcpy(makes[j-1],make);
					
					t=volumes[j];
					volumes[j]=volumes[j-1];
					volumes[j-1]=t;
					
					t=prices[j];
					prices[j]=prices[j-1];
					prices[j-1]=t;
					
					t=durations[j];
					durations[j]=durations[j-1];
					durations[j-1]=t;
				}
			}
		}
	}
}			
int main(){
	char names[100][21], makes[100][21];
	int volumes[100], prices[100], durations[100];
	int n=0;
	int choice;
	int pos;
	do{
		choice=menu();
		switch(choice){
			case 1:
					addname(makes,names, volumes, prices,durations,n);
					break;
			case 2:
					searchMake(makes, names, volumes, prices,durations, n);
					break;
			case 3:
					searchVolume(makes, names, volumes, prices,durations, n);
					break;
			case 4:
					if(n==0){puts("\nEmpty list\n");}
					else{
					print(makes, names, volumes, prices, durations, n);
					printf("The names after being aranged:\n");
					Asce(makes, names, volumes, prices, durations,n);
					print(makes, names, volumes, prices, durations, n);
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

