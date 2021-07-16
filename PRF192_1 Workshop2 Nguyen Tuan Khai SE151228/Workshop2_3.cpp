#include <stdio.h>
int main(){
double S=0;
int x;
printf("The Sum is 0\n");
printf("Add the intergers to sum:\n");
scanf("%d", &x);
	do{			
		if(x!=0){
			S=S+x;
	}}
	while(x!=0);
	printf("The result is:%lf", S);
	}
