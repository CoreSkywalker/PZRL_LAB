#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	long modul;
	char type[3];
} Op;

Op translate(char* str)
{
	Op tmp;
	if (str[0] == '~')
	{
		sscanf(str, "~%s", str);
		printf("%s\n", str);
		translate(str);
	}
	if (str[0] == '0')
	{
		if (str[1] == 'x')
		{
			tmp.modul = strtol(str, NULL, 16);
			sprintf(tmp.type, "%s", "hex");
		}
		else
		{
			tmp.modul = strtol(str, NULL, 8);
			sprintf(tmp.type, "%s", "oct");
		}
	}
	else
	{
		tmp.modul = strtol(str, NULL, 2);
		sprintf(tmp.type, "%s", "bin");
	}
	return tmp;
}

int main()
{
	char buffer[256];
	printf("Введите выражение\n");
	fgets(buffer, 256, stdin);
	char* p1 = strtok(buffer, " ");
	if (p1[0] != '~')
	{
		char* p2 = strtok(NULL, " ");
		char* p3 = strtok(NULL, " ");
		Op num1, num2;
		num1 = translate(p1);
		num2 = translate(p3);
		if (strcmp(num1.type, num2.type) != 0)
		{
			printf("Error: не совпадают основания СС\n");
			exit(1);
		}
		printf("%ld %s\n", num1.modul, num1.type);
		printf("%ld %s\n", num2.modul, num2.type);

	}
	else
	{
		Op num1;
		num1 = translate(p1);
		printf("%ld %s\n", num1.modul, num1.type);
	}

	return 0;
}
