#include<stdio.h>
#include"bin.h"

void bin_operation(long num1, long num2, char operation)
{
	switch (operation)
	{
		case '+':
		{
			long tmp = num1 + num2;
			printf("%ld (%ld)\n", tmp, tmp);
			break;
		}
		case '-':
		{
			long tmp = num1 - num2;
			printf("%ld (%ld)\n", tmp, tmp);
			break;
		}
		case '*':
		{
			long tmp = num1 * num2;
			printf("%ld (%ld)\n", tmp, tmp);
			break;
		}
		case '%':
		{
			double tmp = (float)num1 / num2;
			printf("%lf (%lf)\n", tmp, tmp);
			break;
		}
		case '&':
		{
			long tmp = num1 & num2;
			printf("%ld (%ld)\n", tmp, tmp);
			break;
		}
		case '|':
		{
			long tmp = num1 | num2;
			printf("%ld (%ld)\n", tmp, tmp);
			break;
		}
		case '^':
			{
			long tmp = num1 ^ num2;
			printf("%ld (%ld)\n", tmp, tmp);
			break;
		}
		case '~':
		{
			long tmp = ~num1;
			printf("%ld (%ld)\n", tmp, tmp);
			break;
		}
		default: printf("Некорректная операция\n");

	}
}
