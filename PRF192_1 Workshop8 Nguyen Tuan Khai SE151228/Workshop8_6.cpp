#include<stdio.h>
#include<string.h>
void readFile (char* fname, char names[][41],char adds[][41], int*marks,int *pn){
	*pn=0;
	FILE* f=fopen(fname,"r");
	if(f!=NULL){
		while(fscanf(f, "%40[^;];%40[^;]; %d%*c" , names[*pn], adds[*pn], &marks[*pn])==3){
			(*pn)++;
		}
		fclose(f);
	}
}
void print(char names[][41],char adds[][41], int* marks, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%-20s%-41s&4d\n", names[i],adds[i], marks[i]);
	}
}
void sort(char names[][41], char adds[][41], int* marks, int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if (marks[j]>marks[j-1]){
				char tName[41];
				strcpy(tName,names[j]);
				strcpy(names[j],names[j-1]);
				strcpy(names[j-1],names[j]);
				char tAdd[41];
				strcpy(tAdd,adds[j]);
				strcpy(adds[j],adds[j-1]);
				strcpy(adds[j-1],tAdd);
				int tMark=marks[j];
				marks[j]=marks[j-1];
				marks[j-1]=tMark;
			}
		}
	}
}
void writeFile(char* fname, char names[][41], char adds[][41], int* marks, int n){
	FILE* f=fopen(fname,"w");
	int i;
	for(i=0;i<n;i++){
		fprintf(f, "%s;%s;%d\n", names[i], adds[i], marks[i]);
	}
	fclose(f);
}
int main(){
	char inFilename[]="students.txt";
	char outFilename[]="students_2.txt";
	char names[50][41];
	char adds[50][41];
	int marks[50];
	int n;
	readFile(inFilename, names, adds, marks, &n);
	sort(names,adds,marks,n);
	printf("Sorted list:\n");
	print(names,adds,marks,n);
	writeFile(outFilename, names,adds,marks,n);
	printf("\nResult file:%s\n",outFilename);
	getchar();
	return 0;
}
