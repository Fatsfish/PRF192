#include<stdio.h>
#include<string.h>
void readFile (char* fname, char names[][41], float*marks,int *pn){
	*pn=0;
	FILE* f=fopen(fname,"r");
	if(f!=NULL){
		while(fscanf(f, "%40[^\n] %d%*c" , names[*pn], &marks[*pn])==2){
			(*pn)++;
		}
		fclose(f);
	}
}
void print(char names[][41], float* marks, int n){
	int i,j;
	int max=0;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(names[j]>names[j-1]){
				max=j;
			}
		}
	}
	printf("%-20s  &4f\n", names[j], marks[j]);
}
void writeFile(char* fname, char names[][41], float* marks, int n){
	FILE* f=fopen(fname,"w");
	int i;
	for(i=0;i<n;i++){
		strupr(names[i]);
		fprintf(f, "%s     ;%4lf\n", names[i], marks[i]);
	}
	fclose(f);
}
int main(){
	char infName[]="input2.txt";
	char outfName[]= "output2.txt";
	char names[100][41];
	float marks[50];
	int n;
	readFile(infName, names, marks, &n);
	writeFile(outfName, names,marks,n);
	printf("\nResult file: %s\n", outfName);
	print(names,marks,n);
	getchar();
	return 0;
}
