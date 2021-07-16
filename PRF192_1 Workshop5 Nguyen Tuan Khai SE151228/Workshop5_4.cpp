#include <stdio.h>
#include <math.h>
int quadraticEquation(double a, double b, double c){
	double x1,x2;
	double x;
	double d;
	if(a==0){
	x=-c/b;
	printf("The value is:x=%lf\n", x);}
	if(a!=0){
		d=b*b-4*a*c;
		if (d>0){
			x1=(b+sqrt(d))/(2*a);
			x2=(b-sqrt(d))/(2*a);
			printf("The values are: %lf and %lf\n", x1,x2);}
		if (d==0){
			x=b/(2*a);
			printf("The only value is: %lf\n",x);}
		if (d<0){	printf("The equation doesn't have results\n");}
		}
	}
int bankDeposit (double m, double r, double n){
	double P;
	if(r>=0&&r<=0.1&&n>0){
	P=m*pow((1+r),n);
	printf("The amount after the duration is:%lf\n", P);}
	else{printf("Please pay attention to conditions and try again!\n");}
	}
int main(){
	int choice;
	int n;
     do   /* Print out the menu and get user choice*/
      {    printf("1- Quadratic equation (ax^2+bx+c=0)\n");
           printf("2- Bank deposit problem\n");
           printf("3- Quit\n");
           printf("Select an operation:");
           scanf("%d", &choice);
           switch(choice) 
               { 	case 1:	double a,b,c;
			   				printf("Type in a,b,c as intergers:");
               				scanf("%lf %lf %lf", &a, &b, &c);
               				quadraticEquation (a,b,c);
                            break;
                    case 2:	double m,n,r;
							printf("Type in deposit, yearly rate and number of years (m,r,n):");
                    		scanf("%lf %lf %lf", &m, &r, &n);
                    		bankDeposit(m,r,n);
							break;
                	case 3: printf("Thank you for using the program.\n");
                				break;
                    default: printf("The option is not supported.");
        }}
     while ( choice >0 & choice<3); 
}
