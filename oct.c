#include<stdio.h>
#include"oct.h"

void oct_print(long n)
{
	long tmp = n;
	if (n < 0)
	{
		printf("-");
		n = -n;
	}
	printf("%o (%ld)\n", n, tmp);
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
