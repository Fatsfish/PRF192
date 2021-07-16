#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char* rTrim (char s[])
{	
	int i= strlen(s)-1;
	while (s[i]==' '){i--;}
	s[i+1]= '\0';
	return s;}
char* lTrim (char s[])
{
	int i=0;
	while (s[i]==' '){i++;}
	if(i>0){strcpy(&s[0], &s[i]);}
	return s;}
char* trim (char s[]){
	rTrim(lTrim(s));
	char *ptr=strstr(s,"  ");
	while(ptr!=NULL){
		strcpy(ptr,ptr+1);
		ptr = strstr(s, "  ");
	}
	return s;
}
char* nameStr(char s[]){
	trim(s);
	strupr(s);
	int i,c;
	char t[10];
	if(s[i]==' '){
		for(c=0;c<i;c++){
			strcpy(s,t);
			s[c]=s[c+1];}
	strcat(s,t);
	printf(s);}}
void add( int value, char *a, char *pn){
	a[*pn]=value;
	(*pn)++;}
void cathoten(char *s){
	strupr(s);
	char *t;
	int i;
	for(i=0;i<=strlen(s)-1;i++)	
	if( s[i]==' '&& s[i-1]!=' ')
	break;
	t=s+i+1;
	s[i]='\0';
	printf("ho lot: ");
	puts(s);
	printf("Ten: ");
	puts(t);
	char k;
	k=strlen(t);
	add(',',t,&k);
	strcat(t,s);}
int main(){
char s[50];
char *t;
printf("Type string:");
fflush(stdin);
scanf("%[^\n]", &s);
trim(s);
cathoten(s);
getchar();
}
