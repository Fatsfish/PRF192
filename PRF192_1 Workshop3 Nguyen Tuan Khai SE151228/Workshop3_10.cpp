#include <stdio.h>
void printMinMaxDigits( int n)
{  int digit; /* Variable for extracting 1 digit */
   int min, max, remainder ; /* Result variables */
   digit = n% 10;  /* get the first rightmost digit: 3 */
   n=n/10; /* 1029, the remainder needs to proceed after*/
   min=max=digit; /* initialize results */
   while (n>0) 
   { digit = n%10; /* Get the next digit */
     n=n/10;
     remainder=digit;
     if (min > digit) {min=digit;} /* update results */
     if (max < digit) {max=digit;}
   }
   printf("The maximum digit is:%d\n", max);
   printf("The minimum digit is:%d\n", min);
}
int main (){
	int n;
	printf("Type the positive interger:");
	do {scanf("%d", n);
		printMinMaxDigits(n);}
	while(n>0);
	}

