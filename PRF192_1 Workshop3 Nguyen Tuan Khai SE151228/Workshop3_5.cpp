#include<stdio.h>
double fibo ( int n) {
	int t1=1, t2=1, f=1, i;
	for (i=3; i<=n; i++) {
      f= t1 + t2;
      t1= t2;
      t2=f;
   }
   return f;
} 
int main(){
	int n;
	printf("type in a random interger:");
	do {
        scanf("%d", &n);
        fibo(n);
    }
    while (n<1);
    printf("the fibonacci value at %d is:%lf\n", n, fibo(n));
}

