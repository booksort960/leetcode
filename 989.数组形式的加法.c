#include <stdio.h>
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) 
{
	int i = 0;
	int s = K;
	while (s)
	{
		s/= 10;
		i++;
	}
	int len = ASize > i ? ASize : i;
	int* p = (int*)malloc(sizeof(int) * (len+1));
	*returnSize = 0;
	int carry = 0;
	int n;
	for (n = ASize - 1; n >= 0||K>0||carry!=0; n--)
	{
		int num1 = n >= 0 ? A[n]:0 ;
		int sum;
		int num = K % 10;
		sum = num1 + num + carry;
		carry = sum / 10;
		sum %= 10;
		p[(*returnSize)++] =sum;
		K /= 10;
	}
	int m = 0;
	int size = *returnSize - 1;
	while(m<size)
	{
		int tmp = p[m];
		p[m] = p[size];
		p[size] = tmp;
		m++;
		size--;
	}
	return p;
}
int main(void)
{
	int returnSize;
	int A[] = { 2,1,5};
	int ASize = 3;
	int K = 806;
	addToArrayForm(A, ASize, K, &returnSize);

	return 0;
}