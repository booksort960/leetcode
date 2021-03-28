int missingNumber(int* nums, int numsSize)
{
	int i = 0;
	int m = 0;
	for (; i < numsSize + 1; i++)
		m += i;
	int j;
	int n = 0;
	for (j = 0; j < numsSize; j++)
		n += nums[j];
	return m - n;
}