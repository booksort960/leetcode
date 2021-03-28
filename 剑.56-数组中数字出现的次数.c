int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
	int n = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		n ^= nums[i];
	}
	int m=0;
	while (n)
	{
		if (n >> m== 1)
		{
			break;
		}
		else
		{
			m++;
		}
	}
	int num1 = n;
	int num2 = n;
	for (int i = 0; i < numsSize; i++)
	{
		if ((nums[i] >> m) & 1)
			num1 ^= nums[i];
		else
			num2 ^= nums[i];
	}
	*returnSize = 2;
	int* p = (int*)malloc(sizeof(int) * (*returnSize));
	p[0] = num1;
	p[1] = num2;
	return p;
}

