#include <stdio.h>
#include <math.h>
int  prime(int n){
     int m = sqrt(n); /* m: square root of n */
     int i;  /* variable having value from 2 to m  */ 
     if (n<2){ 
	 return 0;} /* Condition 1 is not satisfied */
     for ( i=2; i<=m; i++){ /* checking the second condition */
     if (n%i==0){ return 0 ; /* n is divided by i ' n is not a prime */
     return 1;}}/* n is a prime */ 
}
int main(){
int n;
int i;
printf("type an interger here:");
     do {
          scanf("%ld", &n);
          int prime(n);
		  }
	 while (n<2);
	 if (prime(n)){
	 printf("the prime number is:%d\n", n);
	 }
	 for(i>=2;i<n;i++)
	 	if(prime(i))
		 {printf("The prime numbers are:%d\n", i);
		 }}
