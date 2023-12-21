#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include"hex.h"

long hex_read(char* str)
{
	char sign = '+';
	if (str[0] == '-')
	{
		sign = '-';
		sscanf(str, "-%s", str);
	}
	sscanf(str, "0x%s", str);
	long s = 0;
	int len = strlen(str) - 1;
	if (str[len] == '\n')
		len -= 1;
	char buffer[3];
	int count = 0;
	for (int i = len; i >= 0; i--)
	{
		switch (str[i])
		{
			case 'a':
			{
				sprintf(buffer, "%s", "10");
				break;

			}
			case 'b':
			{
				sprintf(buffer, "%s", "11");
				break;

			}
			case 'c':
			{
				sprintf(buffer, "%s", "12");
				break;

			}
			case 'd':
			{
				sprintf(buffer, "%s", "13");
				break;

			}
			case 'e':
			{
				sprintf(buffer, "%s", "14");
				break;

			}
			case 'f':
			{
				sprintf(buffer, "%s", "15");
				break;

			}
			default:
			{
				sprintf(buffer, "%c", str[i]);
			}
		}
		if (str[i] > 'f' || !(isalnum(str[i])))
		{
			printf("Error!\n");
			exit(1);
		}
		s += atoi(buffer) * pow(16, count++);
	}
	if (sign == '-')
		s = -s;
	return s;
}


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
			if (num2 == 0)
			{
				printf("Zero division\n");
				exit(1);
			}

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
