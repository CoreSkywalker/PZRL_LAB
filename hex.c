#include<stdio.h>
#include"hex.h"

void hex_operation(long num1, long num2, char operation)
{
	switch (operation)
	{
		case '+':
		{
			long tmp = num1 + num2;
			printf("0x%x (%ld)\n", tmp, tmp);
			break;
		}
		case '-':
		{
			long tmp = num1 - num2;
			printf("0x%x (%ld)\n", tmp, tmp);
			break;
		}
		case '*':
		{
			long tmp = num1 * num2;
			printf("0x%x (%ld)\n", tmp, tmp);
			break;
		}
		case '%':
		{
			long tmp = num1 % num2;
			printf("0x%x (%ld)\n", tmp, tmp);
			break;
		}
		case '&':
		{
			long tmp = num1 & num2;
			printf("0x%x (%ld)\n", tmp, tmp);
			break;
		}
		case '|':
		{
			long tmp = num1 | num2;
			printf("0x%x (%ld)\n", tmp, tmp);
			break;
		}
		case '^':
			{
			long tmp = num1 ^ num2;
			printf("0x%x (%ld)\n", tmp, tmp);
			break;
		}
		case '~':
		{
			long tmp = ~num1;
			printf("0x%x (%ld)\n", tmp, tmp);
			break;
		}
		default: printf("Некорректная операция\n");

	}
}
