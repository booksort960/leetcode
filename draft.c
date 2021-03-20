//É¾³ıÖØ¸´Ïî
//int removeDuplicates(int* nums, int numsSize) 
//{
//	int pre = 0;
//	int new = 0;
//	nums[new] = nums[pre];
//	int num = 1;
//	if (numsSize == 0)
//		return 0;
//	for (pre=1; pre < numsSize; pre++)
//	{
//		if (nums[new] != nums[pre])
//		{
//			new++;
//			nums[new] = nums[pre];
//			num++;
//		}
//		
//	}
//	return num;
//}
//int maxProfit(int* prices, int pricesSize)
//{
//	int max = 0;
//	if (pricesSize == 0)
//		return 0;
//	for (int i = 0; i < pricesSize - 1; i++)
//	{
//		if (prices[i] < prices[i + 1])
//		{
//			max = prices[i + 1] - prices[i] + max;
//		}
//	}
//	return max;
//}
//int maxProfit(int* prices, int pricesSize)
//{
//	int max = 0;
//	for (int i = 0; i < pricesSize - 1; i++)
//	{
//		if (prices[i] < prices[i + 1])
//		{
//			max = prices[i + 1] - prices[i] + max;
//		}
//	}
//	return max;
//}
//void rotate1(int* num,int k)
//{
//	int head = 0;
//	int end = k - 1;
//	while (head<end)
//	{
//		int n = *(num+head);
//		*(num + head) = *(num + end);
//		*(num + end) = n;
//		head++;
//		end--;
//	}
//}
//void rotate(int* nums, int numsSize, int k) 
//{
//	k %= numsSize;
//	rotate1(nums+numsSize-k,k);
//	rotate1(nums,numsSize-k);
//	rotate1(nums,numsSize);
//
//}
//void swap(int* a, int* b) {
//    int t = *a;
//    *a = *b, * b = t;
//}
//
//void reverse(int* nums, int start, int end) {
//    while (start < end) {
//        swap(&nums[start], &nums[end]);
//        start += 1;
//        end -= 1;
//    }
//}
//
//void rotate(int* nums, int numsSize, int k) {
//    k %= numsSize;
//    reverse(nums, 0, numsSize - 1);
//    reverse(nums, 0, k - 1);
//    reverse(nums, k, numsSize - 1);
//}
//
//int (cmp)(const void* e1,const void* e2)
//{
//	return (*(int*)e1) - (*(int*)e2);
//}
//bool containsDuplicate(int* nums, int numsSize) 
//{
//	int n = 0;
//	qsort(nums, numsSize, sizeof(int), cmp);
//	for (int i = 0; i < numsSize - 1; i++)
//	{
//		if (nums[i] == nums[i + 1])
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int singleNumber(int* nums, int numsSize) 
//{
//	int n = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		n ^= nums[i];
//	}
//	return n;
//}
int cmp(const void* e1, const void* e2)
{
	return (*(int*)e1) - (*(int*)e2);
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) 
{
	qsort(nums1, nums1Size, sizeof(int), cmp);
	qsort(nums2, nums2Size, sizeof(int), cmp);
	int* ptr = (int*)malloc(sizeof(int));
	int j;
	int n = 0;
	for (int i = 0, j = 0; i < nums1Size && j < nums2Size;)
	{
		if (nums1[i] > nums2[j])
		{
			j++;
		}
		else if (nums1[i] < nums2[j])
		{
			i++;
		}
		else
		{
			ptr = (int*)realloc(ptr, sizeof(int) * (n + 1));
			ptr[n] = nums1[i];
			n++;
			i++;
			j++;
		}

	}

	return ptr;
}