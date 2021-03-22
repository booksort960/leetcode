int cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void moveZeroes(int* nums, int numsSize) 
{
	if (numsSize < 1)
		return;
	int front = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != 0)
		{
			nums[front] = nums[i];
			++front;
		}
	}
	qsort(nums, front+1, sizeof(int), cmp);
	while (front < numsSize)
	{
		nums[front] = 0;
		++front;
	}

}