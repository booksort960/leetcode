//int* singleNumber(int* nums, int numsSize, int* returnSize)
//{
//	int n = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		n ^= nums[i];
//	}
//	int m = 0;
//	while (m<32)
//	{
//		if (n & (1 << m))
//			break;
//		else
//			++m;
//	}
//	int a = n;
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] & (1 << m))
//			n ^= nums[i];
//		else
//			a ^= nums[i];
//	}
//	int* ret = (int*)malloc(sizeof(int) * 2);
//	ret[0] = n;
//	ret[1] = a;
//	*returnSize = 2;
//	return ret;
//}
//int* singleNumber(int* nums, int numsSize, int* returnSize)
//{
//	int n = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		n ^= nums[i];
//	}
//	int m = 0;
//	while (m < 32)
//	{
//		if (n & (1 << m))
//			break;
//		else
//			++m;
//	}
//	int a = 0, b = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] & (1 << m))
//			b ^= nums[i];
//		else
//			a ^= nums[i];
//	}
//	int* ret = (int*)malloc(sizeof(int) * 2);
//	ret[0] = a;
//	ret[1] = b;
//	*returnSize = 2;
//	return ret;
//}
//int* singleNumber(int* nums, int numsSize, int* returnSize)
//{
//	int n = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		n ^= nums[i];
//	}
//	int m = 0;
//	while (m < 32)
//	{
//		if ((n >> m) & 1)
//			break;
//		else
//			++m;
//	}
//	int a = n;
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] >> m & 1)
//			n ^= nums[i];
//		else
//			a ^= nums[i];
//	}
//	int* ret = (int*)malloc(sizeof(int) * 2);
//	ret[0] = n;
//	ret[1] = a;
//	*returnSize = 2;
//	return ret;
//}