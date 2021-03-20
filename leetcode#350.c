int cmp(const void* e1, const void* e2)
{
	return (*(int*)e1) - (*(int*)e2);
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	qsort(nums1, nums1Size, sizeof(int), cmp);
	qsort(nums2, nums2Size, sizeof(int), cmp);
	int min = nums1Size > nums2Size ? nums2Size : nums1Size;
	int* ptr = (int*)malloc(sizeof(int) * min);
	int j;
	*returnSize = 0;
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
			ptr[*returnSize] = nums1[i];
			*returnSize += 1;
			i++;
			j++;
		}

	}

	return ptr;
}