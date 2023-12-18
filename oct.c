#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include"oct.h"

long oct_read(char* str)
{
	char sign = '+';
	if (str[0] == '-')
	{
		sign = '-';
		sscanf(str, "-%s", str);
	}
	sscanf(str, "0%s", str);
	long s = 0;
	int len = strlen(str) - 1;
	if (str[len] == '\n')
		len -= 1;
	char buffer[2];
	int count = 0;
	for (int i = len; i >= 0; i--)
	{
		sprintf(buffer, "%c", str[i]);
		if (atoi(buffer) > 7 || !(isdigit(str[i])))
		{
			printf("Error!\n");
			exit(1);
		}
	
		s += atoi(buffer) * pow(8, count++);
	}
	if (sign == '-')
		s = -s;
	return s;
}


void oct_print(long n)
{
	long tmp = n;
	if (n < 0)
	{
		printf("-");
		n = -n;
	}
	printf("0%o (%ld)\n", n, tmp);
}

void oct_operation(long num1, long num2, char operation)
{
	switch (operation)
	{
		case '+':
		{
			long tmp = num1 + num2;
			oct_print(tmp);
			break;
		}
		case '-':
		{
			long tmp = num1 - num2;
			oct_print(tmp);
			break;
		}
		case '*':
		{
			long tmp = num1 * num2;
			oct_print(tmp);
			break;
		}
		case '%':
		{
			long tmp = num1 % num2;
			oct_print(tmp);
			break;
		}
		case '&':
		{
			long tmp = num1 & num2;
			oct_print(tmp);
			break;
		}
		case '|':
		{
			long tmp = num1 | num2;
			oct_print(tmp);
			break;
		}
		case '^':
		{
			long tmp = num1 ^ num2;
			oct_print(tmp);
			break;
		}
		case '~':
		{
			long tmp = ~num1;
			oct_print(tmp);
			break;
		}
		default: printf("Некорректная операция\n");

	}
}
