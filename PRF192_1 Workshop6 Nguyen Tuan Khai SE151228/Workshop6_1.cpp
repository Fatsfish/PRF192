#include <stdio.h>
int checkISBN (int n){
	int I[11];
	int C[10];
	int T;
	int i;
	if (n>1000000000){
		for(i=10;i>=0;i--){
			I[i]=n%10;
			n=n/10;
		}
	C[1]=I[1]*10;
	C[2]=I[2]*9;
	C[3]=I[3]*8;
	C[4]=I[4]*7;
	C[5]=I[5]*6;
	C[6]=I[6]*5;
	C[7]=I[7]*4;
	C[8]=I[8]*3;
	C[9]=I[9]*2;
	T= C[1]+C[2]+C[3]+C[4]+C[5]+C[6]+C[7]+C[8]+C[9]+I[10];	
	if(T%11==0) {printf("This is a valid ISBN\n");}	else {printf("This is an invalid ISBN\n");}}
	if(n==0){return 0;
	}
	else{
	printf("The ISBN is invalid (must larger than 999,999,999), try again!\n");}}
int main(){
	int n;
	printf("ISBN validator ========================\n");
	do{
	printf("Type in the ISBN to check (0 to quit)):");
	scanf("%d", &n);
	checkISBN(n);}
	while(n!=0);
	printf("Have a nice day!\n");
}
