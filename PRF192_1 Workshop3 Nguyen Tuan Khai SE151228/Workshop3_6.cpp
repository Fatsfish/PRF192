#include <stdio.h>
int isFibonacci (int n) 
{  int t1=1, t2=1, f=1;
   if (n==1){return 1;} /* n belongs to the Fibonacci sequence*/
   while (f<n)           /* Find out the Fibo number f to n */
   {   f= t1 + t2;
       t1=t2;
       t2=f;
   }  
   return n==f;  /* if n==f ' n is Fibo element ' return 1 */
}

int main (){
	int n;
	printf("type in an interger:");
	do {
        scanf("%d", &n);
     }
     while (n<1);
     if( isFibonacci(n)==1){
	 printf("It is a Fibonacci element.");}
     else {printf("It is not a Fibonacci element.");
	 printf("Have a good day.");}	
}
