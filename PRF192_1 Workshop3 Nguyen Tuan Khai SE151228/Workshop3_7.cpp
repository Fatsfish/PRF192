#include <stdio.h>
int sumDigits (int n)
{   int sum=0; /* initialize sum of digits */
    do{  
		int remainder = n%10 ; /* Get a digit at unit position */
      	n = n/10;
      	sum += remainder;
   }
while (n>0);
return sum;
}
int main(){
	int S;
	int n;
	printf("type in a random positive interger:");
	do{
		scanf("%d", &n);
		if(n>=0){
			S= sumDigits(n);
			printf("The sum of its decimal digits is:%d\n", S);
		}
	}
	while (n>=0);
	printf("%d is a negative number, have a good day.",n);
}
