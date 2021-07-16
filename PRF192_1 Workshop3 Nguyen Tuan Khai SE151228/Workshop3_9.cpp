#include <stdio.h>
int  gcd( int a, int b)
{  while ( a != b ){
       if (a>b){
	   a -=b;}
       else {
	   b -= a;}}
	return a;
}
int lcm ( int a, int b)
{ return a*b/ gcd(a,b);
}
int main(){
	int a,b,m,d;
	printf("Type in 2 random integers:");
	do
{  scanf("%d %d", a, b);
}
while ( a<=0 || b <=0);
d = gcd(a,b);
m = lcm (a,b);
printf("The greatest common divisor is:%d\n", d);
printf("The least common multiple is:%d\n", m);
}
