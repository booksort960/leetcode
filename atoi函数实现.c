#include <stdio.h>
//int myAtoi(char* s)
//{
//	int flag=1;
//	int sum = 0;
//	
//	while (isspace(*s))
//	{
//		s++;
//		continue;
//	}
//	if (isalpha(*s)||*s=='\0'||s==NULL)
//		return 0;
//	if (*s == '-')
//	{
//		flag = -1;
//		s++;
//	}
//	else if (*s == '+')
//	{
//		flag = 1;
//		s++;
//	}
//	while (isdigit(*s))
//	{
//		sum = sum * 10 +flag*(*s-'0');
//		s++;
//	}
//	/*if (sum > INT_MAX)
//		return INT_MAX;
//	else if (sum < INT_MIN)
//		return INT_MIN;*/
//	return sum;
//}
int main(void)
{
	myAtoi("   -42");
}
int myAtoi(char* s)
{
	int flag = 1;
	long long sum = 0;

	while (isspace(*s))
	{
		s++;
		continue;
	}
	if (isalpha(*s) || *s == '\0' || s == NULL)
		return 0;
	if (*s == '-')
	{
		flag = -1;
		s++;
	}
	else if (*s == '+')
	{
		flag = 1;
		s++;
	}
	while (isdigit(*s))
	{
		sum = sum * 10 + flag * (*s - '0');

		if (sum > INT_MAX)
			return INT_MAX;
		else if (sum < INT_MIN)
			return INT_MIN;
		s++;
	}


	return sum;
}