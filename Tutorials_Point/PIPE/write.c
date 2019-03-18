#include<stdio.h>                                                       

int main()
{
    FILE *fp, *fp1;
	fp = fopen("a.c", "r");
	if(fp == NULL){
		printf("File does not exist\n");
		return;
	}
	
	char ch;
	fp1 = open("b.c", w);
	while((ch = fgetc(fp)) != EOF){
		fputs(ch, fp1);
	}
	fclose(fp);
	fclose(fp1);
	return;
}
