#include<stdio.h>
#include<stdlib.h>
#include"bin.h"

void bin_print(long n)
{
	int a[50];
	long tmp = n;
	if (n < 0)
	{
		printf("-");
		n = -n;
	}
	int index;
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
