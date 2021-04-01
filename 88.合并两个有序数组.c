//先合并在排序
int cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{

	int j = 0;
	for (int i = m; i < n + m && j < n; i++)
	{
		nums1[i] = nums2[j];
		j++;
	}
	qsort(nums1, m + n, sizeof(int), cmp);
}


/*if (nums1[p1] < nums2[p2])
		{
			nums1[p--] = nums2[p2];
			p2--;
		}
		else if(nums1[p1]>nums2[p2])
		{
			nums1[p--] = nums1[p1];
			p1--;
		}
		else
		{
			nums1[p--] = nums1[p1];
			p1--;
			nums1[p--] = nums2[p2];
			p2--;
		}*/
//int main(void)
//{
//	int nums1[] = { 1,2,3 };
//	void merge(num1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//
//	return 0;
//}
