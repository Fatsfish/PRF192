#include <stdio.h>
double factorial ( int n) {
    double p=1;
    int i;
    for (i=2; i<=n; i++) {
	p*=i;}
    return p;
} 
int main(){
	int n;
	printf("type in a random interger:");
     do {
             scanf("%d", &n);
     }
     while (n<0);
     printf("the factorial of the interger is:%lf\n", factorial(n));
}


