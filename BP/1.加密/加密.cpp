#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp1;
	FILE *fp2;
	fp1 = fopen("in2.txt","r");
	fp2 = fopen("out2.txt","w");

	char ch = fgetc(fp1);

	while(ch != EOF)
	{
		char k = rand();
		ch = ch ^ k;
		fprintf(fp2, "%c", ch);
		ch = fgetc(fp1);
	}
	fclose(fp1);
	return 0;
}