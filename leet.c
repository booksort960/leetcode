#include <stdio.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
	int* p = malloc(sizeof(int) * digitsSize);
	int i = digitsSize - 1;	
	for (; i >=0; i--)
	{
		digits[i] += 1;
		if (digits[i] % 10 != 0)
		{
			*returnSize = digitsSize;
			return digits;
		}
		digits[i] %= 10;
	}
	p = (int*)realloc(p,sizeof(int) * (digitsSize + 1));
	for (int i = 0; i < digitsSize; i++)
	{
		p[i + 1] = digits[i];
	}
	p[0] = 1;
	*returnSize = digitsSize + 1;
	return p;
}
//int* plusOne(int* digits, int digitsSize, int* returnSize)
//{
//	int sum = 0;
//	for (int i = 0; i < digitsSize; i++)
//	{
//		sum = sum * 10 + digits[i];
//	}
//	sum += 1;
//	int i = 0;
//	int num = sum;
//	while (num)
//	{
//		i++;
//		num /= 10;
//	}
//	*returnSize = i;
//	int* p =(int*)malloc(sizeof(int) * (*returnSize));
//	i--;
//	while (sum)
//	{
//		p[i] = sum % 10;
//		sum /= 10;
//		i--;
//	}
//	return p;
//}
int main(void)
{
	int n;
	int arr[] = { 9 };
	plusOne(arr, sizeof(arr) / sizeof(arr[0]), &n);

}
