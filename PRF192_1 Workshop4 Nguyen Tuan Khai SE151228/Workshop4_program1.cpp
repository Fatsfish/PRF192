#include <stdio.h>
#include<math.h>
int  prime(int n){
	int m = sqrt(n); /* m: square root of n */
     int i;  /* variable having value from 2 to m  */ 
     if (n<2){ 
	 return 0;} /* Condition 1 is not satisfied */
     for ( i=2; i<=m; i++){ /* checking the second condition */
     if (n%i==0){ return 0 ; /* n is divided by i ' n is not a prime */
     return 1;}}/* n is a prime */ 
}
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
     if (min > remainder) min=remainder; /* update results */
     if (max < remainder) max=remainder;
   }
   printf("The maximum digit is:%d\n", max);
   printf("The minimum digit is:%d\n", min);
}
int main(){
	int choice;
	int n;
     do   /* Print out the menu and get user choice*/
      {    printf("1- Process primes\n");
           printf("2- Print min, max digit in an integer \n");
           printf("3- Quit\n");
           printf("Select an operation:");
           scanf("%d", &choice);
           switch(choice) 
               {  case 1: do
                               {printf("type an interger here:");   
							   scanf("%d", &n);
	                    }
                               while(n<0);
                               if ( prime(n)==1){
							   printf(" It is a prime\n");}
                               else{
								printf(" It is not a prime\n");}
                               break;
                  case 2: do
                                {printf("Type the positive interger:");  
								 scanf("%d", &n);
                                }
                                while(n<0);
                                printMinMaxDigits(n) ;
                               break;
                	case 3: printf("Thank you for using the program.");
                				break;
                    default: printf("The option is not supported.");
                 }
        }
     while ( choice >0 & choice<3); 
}
