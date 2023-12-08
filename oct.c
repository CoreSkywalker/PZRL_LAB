#include<stdio.h>
#include"oct.h"

void oct_operation(long num1, long num2, char operation)
{
	switch (operation)
	{
		case '+':
		{
			long tmp = num1 + num2;
			printf("%o (%ld)\n", tmp, tmp);
			break;
		}
		case '-':
		{
			long tmp = num1 - num2;
			printf("%o (%ld)\n", tmp, tmp);
			break;
		}
		case '*':
		{
			long tmp = num1 * num2;
			printf("%o (%ld)\n", tmp, tmp);
			break;
		}
		case '%':
		{
			double tmp = (float)num1 / num2;
			printf("%o (%lf)\n", tmp, tmp);
			break;
		}
		case '&':
		{
			long tmp = num1 & num2;
			printf("%o (%ld)\n", tmp, tmp);
			break;
		}
		case '|':
		{
			long tmp = num1 | num2;
			printf("%o (%ld)\n", tmp, tmp);
			break;
		}
		case '^':
		{
			long tmp = num1 ^ num2;
			printf("%o (%ld)\n", tmp, tmp);
			break;
		}
		case '~':
		{
			long tmp = ~num1;
			printf("%o (%ld)\n", tmp, tmp);
			break;
		}
		default: printf("Некорректная операция\n");

	}
}
