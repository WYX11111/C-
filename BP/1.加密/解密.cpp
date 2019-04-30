#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp1;
	fp1 = fopen("out.txt","r");

	char ch = fgetc(fp1);

	while(ch != EOF)
	{
		char k = rand();
		ch = ch ^ k;
		printf("%c", ch);
		ch = fgetc(fp1);
	}
	fclose(fp1);
	return 0;
}