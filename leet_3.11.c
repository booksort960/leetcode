//int reverse(int x)
//{
//	long long sum = 0;
//	long long num = x;
//	while (num)
//	{
//		sum = sum * 10 + num % 10;
//		num /= 10;
//	}
//	return ((sum <= INT_MAX) && (sum >= INT_MIN)) ? sum : 0;
//}
//int reverse(int x)
//{
//	long sum = 0;
//	int num = x;
//	while (x)
//	{
//		sum = sum * 10 + x % 10;
//		x /= 10;
//	}
//	if (num < 0)
//		return sum * (-1);
//	return sum;
//}
//bool isPalindrome(int x)
//{
//	int rev = reverse(x);
//	if (rev == x)
//		return 1;
//	return 0;
//}
//int reverse(int x)
//{
//	long sum = 0;
//	while (x)
//	{
//		sum = sum * 10 + x % 10;
//		x /= 10;
//	}
//	return sum;
//}
//bool isPalindrome(int x)
//{
//	if (x < 0)
//		return 0;
//	else
//	{
//		int rev = reverse(x);
//		if (rev == x)
//			return 1;
//		return 0;
//	}
//}
//bool isPalindrome(int x)
//{
//	if (x < 0)
//		return 0;
//	else
//	{
//		long sum = 0;
//		while (x)
//		{
//			sum = sum * 10 + x % 10;
//			x /= 10;
//		}
//		if (sum == x)
//			return 1;
//		return 0;
//	}
//}
//int rep(char n);
//int romanToInt(char* s)
//{
//	int sum = 0;
//
//	int len = strlen(s);
//	for (int i = 0; i < len - 1; i++)
//	{
//
//		sum = (rep(s[i]) < rep(s[i + 1])) ? sum + rep(s[i + 1]) - rep(s[i]) : sum + rep(s[i]);
//		if (i == len - 2)
//			sum += rep(s[len - 1]);
//	}
//	return sum;
//}
//int rep(char n)
//{
//	switch (n)
//	{
//	case 'I':
//		return 1;
//	case 'V':
//		return 5;
//	case 'X':
//		return 10;
//	case 'L':
//		return 50;
//	case 'C':
//		return 100;
//	case 'D':
//		return 500;
//	case 'M':
//		return 1000;
//	default:
//		return 0;
//	}
//}
//int rep(char n)
//{
//	switch (n)
//	{
//	case 'I':
//		return 1;
//	case 'V':
//		return 5;
//	case 'X':
//		return 10;
//	case 'L':
//		return 50;
//	case 'C':
//		return 100;
//	case 'D':
//		return 500;
//	case 'M':
//		return 1000;
//	}
//}
//int romanToInt(char* s)
//{
//	int sum = 0;
//
//	int len = strlen(s);
//	int pre=rep(s[0]);
//	for (int i = 1; i < len ; i++)
//	{
//		if (pre<rep(s[i]))//出现5-1的情况
//		{
//			sum -= pre;
//		}
//		else
//		{
//			sum += rep(s[i]);
//		}
//		pre = rep(s[i]);
//	}
//	return sum;
//}
//int rep(char n);
//int romanToInt(char* s)
//{
//	int sum = 0;
//	int len = strlen(s);
//	int pre = rep(s[0]);
//	for (int i = 1; i < len; i++)
//	{
//		if (pre < rep(s[i]))//出现5-1的情况
//		{
//			sum -= pre;
//		}
//		else
//		{
//			sum += pre;
//		}
//		pre = rep(s[i]);
//	}
//	sum += pre;
//	return sum;
//}
//int rep(char n)
//{
//	switch (n)
//	{
//	case 'I':
//		return 1;
//	case 'V':
//		return 5;
//	case 'X':
//		return 10;
//	case 'L':
//		return 50;
//	case 'C':
//		return 100;
//	case 'D':
//		return 500;
//	case 'M':
//		return 1000;
//	default:
//		return 0;
//	}
//}