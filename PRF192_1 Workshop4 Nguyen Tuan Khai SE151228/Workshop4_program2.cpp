#include <stdio.h>
int valid ( int d, int m, int y) {
int maxd = 31; /*max day of months 1, 3, 5, 7, 8, 10, 12 */
/* basic checking */
if ( d<1 || d>31 || m<1 || m>12) {return 0;}
/* update maxd of a month */
if ( m==4 || m==6 || m==9 || m==11) {maxd=30;}
else if (m==2) {
            /* leap year? */
             if ( y%400==0 || y%4==0 && y%100!=0){maxd=29;}
             else maxd=28;
       }
return d<=maxd; 
}  
double fibo ( int n) {
	int t1=1, t2=1, f=1, i;
 		if(n==1){printf("The Fibonacci sequence value is:%d\n",t1);}
 		if(n==2){printf("The Fibonacci sequence value is:%d\n",t1);
 		printf("The Fibonacci sequence value is:%d\n",t2);}
 		if(n>=3){
		 printf("The Fibonacci sequence value is:%d\n",t1);
		 printf("The Fibonacci sequence value is:%d\n",t2);
	for (i=3; i<=n; i++) {
      f= t1 + t2;
      t1= t2;
      t2=f;
      printf("The Fibonacci sequence value is:%d\n",f);
   }}
   return f;
} 
int main(){
	int choice;
	int n;
     do   /* Print out the menu and get user choice*/
      {    printf("1- Fibonacci sequence numbers\n");
           printf("2- Check date\n");
           printf("3- Quit\n");
           printf("Select an operation:");
           scanf("%d", &choice);
           switch(choice) 
               {  case 1: 	printf("type in a random interger:");
							do {
							        scanf("%d", &n);
							        fibo(n);
							    }
							    while (n<1);
							    break;
                  case 2:		int d,m,y;
								printf("Type in day month year:\n");
							    scanf("%d %d %d", &d, &m, &y);
							    if(valid(d,m,y)){printf("valid date\n");}
							    else{ printf("invalid date\n");}
                               break;
                	case 3: printf("Thank you for using the program.");
                				break;
                    default: printf("The option is not supported.");
        }}
     while ( choice >0 & choice<3); 
}
