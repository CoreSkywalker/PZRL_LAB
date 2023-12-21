#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include"bin.h"

long bin_read(char* str)
{
	char sign = '+';
	if (str[0] == '-')
	{
		sign = '-';
		sscanf(str, "-%s", str);
	}
	long s = 0;
	int len = strlen(str) - 1;
	if (str[len] == '\n')
		len -= 1;
	char buffer[2];
	int count = 0;
	for (int i = len; i >= 0; i--)
	{
		sprintf(buffer, "%c", str[i]);
		if (atoi(buffer) > 1 || !(isdigit(str[i])))
		{
			printf("Error!\n");
			exit(1);
		}
		s += atoi(buffer) * pow(2, count++);
	}
	if (sign == '-')
		s = -s;
	return s;
}

void bin_print(long n)
{
	int a[50];
	a[0] = 0;
	long tmp = n;
	if (n < 0)
	{
		printf("-");
		n = -n;
	}
	int index = 0;
	for (int i = 0; n > 0; i++)
	{
		a[i] = n % 2;
		n /= 2;
		index = i;
	}
	for (int i = index; i >= 0; i--)
	{
		printf("%d", a[i]);
	}
	printf(" (%ld)\n", tmp);
}

void bin_operation(long num1, long num2, char operation)
{
	switch (operation)
	{
		case '+':
		{
			long tmp = num1 + num2;
			bin_print(tmp);
			break;
		}
		case '-':
		{
			long tmp = num1 - num2;
			bin_print(tmp);
			break;
		}
		case '*':
		{
			long tmp = num1 * num2;
			bin_print(tmp);
			break;
		}
		case '%':
		{
			if (num2 == 0)
			{
				printf("Zero division\n");
				exit(1);
			}
			long tmp = num1 % num2;
			bin_print(tmp);
			break;
		}
		case '&':
		{
			long tmp = num1 & num2;
			bin_print(tmp);
			break;
		}
		case '|':
		{
			long tmp = num1 | num2;
			bin_print(tmp);
			break;
		}
		case '^':
			{
			long tmp = num1 ^ num2;
			bin_print(tmp);
			break;
		}
		case '~':
		{
			long tmp = ~num1;
			bin_print(tmp);
			break;
		}
		default: printf("Некорректная операция\n");

	}
}
