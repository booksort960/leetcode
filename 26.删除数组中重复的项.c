//int removeDuplicates(int* nums, int numsSize) 
//{
//	int j = 0;
//	int* p = nums;
//	int* front = nums;
//	int* back = nums;
//	int n = 0;
//	int num = 0;
//	int flag = 0;
//	for (int i = 1; i < numsSize; i++)
//	{
//		if (front[n] == back[i])
//		{
//			continue;
//		}
//		else
//		{
//			++num;
//			n++;
//			front[n] = back[i];
//			flag = 0;
//		}
//	}
//	return num+1;
//}
int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	int* front = nums;
	int* back = nums;
	int n = 0;
	for (int i = 1; i < numsSize; i++)
	{
		if (front[n] != back[i])
		{
			n++;
			front[n] = back[i];
		}
	}

	return n + 1;
}