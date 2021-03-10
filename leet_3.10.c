#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//int* twoSum(int* num, int len, int target, int* retsize)
//{
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = i + 1; j < len; j++)
//		{
//			if (target == (num[i] + num[j]))
//			{
//				int* ret = (int*)malloc(sizeof(int) * 2);
//				ret[0] = i;
//				ret[1] = j;
//				*retsize = 2;
//				return ret;
//			}
//		}
//	}
//	*retsize = 0;
//	return NULL;
//}

//int* retm(int* num, int target,int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = i + 1; j < len; j++)
//		{
//			if (num[i]+num[j]==target)
//			{
//				int* ret = (int*)malloc(sizeof(int) * 2);
//				ret[0] = i;
//				ret[j] = j;
//				return ret;
//			}
//		}
//	}
//	return NULL;
//}
int twosum(int a, int len,int i,int*num)
{
	for (int j = i + i; j < len; j++)
	{
		if (a == num[j])
			return j;
	}
	return -1;
}
int main(void)
{
	int j;
	int target;
	int num[1000];
	int i = 0;
	while (~scanf("%d", &num[i]))
	{
		i++;
	}
	scanf("%d", &target);
	int len = sizeof(num) / sizeof(num[0])-1;
	for (int i = 0; i < len; i++)
	{
		if ((j = twosum(target - num[i], len, i, num)) != -1)
		{
			printf("[%d,%d]", i, j);
		}
	}
	return 0;
}