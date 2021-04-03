//#include <stdio.h>
//int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
//{
//	int max ;
//	int front = 0;
//	int last = front + k - 1;
//	*returnSize = 0;
//	int* p = (int*)malloc(sizeof(int) * numsSize);
//	while (last <= numsSize - 1)
//	{
//		max = nums[front];
//		for (int i = front; i <= last; i++)
//		{
//			max = max > nums[i] ? max : nums[i];
//		}
//		p[(*returnSize)++] = max;
//		front++;
//		last++;
//	}
//	return p;
//}
//int main(void)
//{
//	int nums[] = { 1,3,-1,-3,5,3,6,7 };
//	int numsSize = 8;
//	int k = 3;
//	int returnSize;
//	maxSlidingWindow(nums, numsSize, k, &returnSize);
//	return 0;
//}