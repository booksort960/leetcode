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