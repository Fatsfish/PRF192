#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Get a random integer between min and max randomly */
int intRandom(int min, int max)
{  /* Refer to the lecture to get algorithm for this task */
	int value;
	value=min+rand()%(max-min);	
}
main(){
int total, x,y, count;
printf("Type in the total of 2 dices (from 2 to 12):");
do
 { scanf("%d", &total);
 
	if(total<2||total>12){
	printf("Sorry, the Sum doesn't exist! Please type again!\n");}
}
while (total<2 || total >12);
printf("Dice Thrower !!\n");
printf("===============\n");
printf("Total sought: %d\n", total);
count =1;
do
{  x= intRandom(1,6);
   y= intRandom(1,6);
   printf("Result of throw %d: %d + %d\n", count, x, y);
   count++;
}
while (x+y != total);
 if(count==1){printf("You got your total in 1 throw! You are so lucky, Congratulation !!!");
}			
	else{printf("You got your total in %d throws!", count);}
}

