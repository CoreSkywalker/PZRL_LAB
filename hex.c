#include<stdio.h>
#include"hex.h"

void hex_print(long n)
{
	long tmp = n;
	if (n < 0)
	{
		printf("-");
		n = -n;
	}
	printf("0x%x (%ld)\n", n, tmp);
}


void hex_operation(long num1, long num2, char operation)
{
	switch (operation)
	{
		case '+':
		{
			long tmp = num1 + num2;
			hex_print(tmp);
			break;
		}
		case '-':
		{
			long tmp = num1 - num2;
			hex_print(tmp);
			break;
		}
		case '*':
		{
			long tmp = num1 * num2;
			hex_print(tmp);
			break;
		}
		case '%':
		{
			long tmp = num1 % num2;
			hex_print(tmp);
			break;
		}
		case '&':
		{
			long tmp = num1 & num2;
			hex_print(tmp);
			break;
		}
		case '|':
		{
			long tmp = num1 | num2;
			hex_print(tmp);
			break;
		}
		case '^':
			{
			long tmp = num1 ^ num2;
			hex_print(tmp);
			break;
		}
		case '~':
		{
			long tmp = ~num1;
			hex_print(tmp);
			break;
		}
		default: printf("Некорректная операция\n");

	}
}
