#include <stdio.h>
int main (){                     
double num1;
double num2;
char op;
double result;               
printf("Type num1 op num2:\n");
scanf( "%lf%c%lf", &num1, &op, &num2);
switch (op)
              {    case '+' : result = num1 + num2;
									printf("The result is:%lf", result);
                                    break;
                   case '-' : result = num1 - num2;
									printf("The result is:%lf", result);
                                    break;
                   case '*' : result = num1 * num2;
									printf("The result is:%lf", result);
                                    break;
                    case '/' : if ( num2==0){
                                        printf("Divide by 0 ");}
                                    else
                                     { result = num1 / num2;
									printf("The result is:%lf", result);
                                     }
                                    break;
                    default: printf("Op is not supported");
                }
getchar();
}
