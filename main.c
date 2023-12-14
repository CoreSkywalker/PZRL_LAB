#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"bin.h"
#include"oct.h"
#include"hex.h"

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
		translate(str);
	}
	if ((str[0] == '0') && (str[1] != '\0') && (str[1] != '\n'))
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
	Op num1, num2;
	char operation;
	if (p1[0] != '~')
	{
		char* p2 = strtok(NULL, " ");
		char* p3 = strtok(NULL, " ");
		operation = p2[0];
		if (operation == '&' || operation == '|' || operation == '^')
		{
			if ((p1[0] == '-') || (p3[0] == '-'))
			{
				printf("Error: отрицательные значения\n");
				exit(1);
			}
		}
		num1 = translate(p1);
		num2 = translate(p3);

		if (strcmp(num1.type, num2.type) != 0)
		{
			printf("Error: не совпадают основания СС\n");
			exit(1);
		}

	}
	else
	{
		num1 = translate(p1);
		num2.modul = 0;
		operation = '~';
	}

	if (strcmp(num1.type, "bin") == 0)
		bin_operation(num1.modul, num2.modul, operation);
	if (strcmp(num1.type, "oct") == 0)
		oct_operation(num1.modul, num2.modul, operation);
	if (strcmp(num1.type, "hex") == 0)
		hex_operation(num1.modul, num2.modul, operation);

	return 0;
}
