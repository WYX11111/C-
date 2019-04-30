#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;

	fp1 = fopen("in2.txt","r");
	fp2 = fopen("out.txt","r");
	fp3 = fopen("out2.txt","r");

	char ch1 = fgetc(fp1);
	char ch2 = fgetc(fp2);
	char ch3 = fgetc(fp3);

	while(ch2 != EOF)
	{
		ch2 = ch3 ^ ch2 ^ ch1;
		printf("%c", ch2);
		ch1 = fgetc(fp1);
		ch2 = fgetc(fp2);
		ch3 = fgetc(fp3);
	}
	fclose(fp1);
	return 0;
}