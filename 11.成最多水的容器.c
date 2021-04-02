int maxArea(int* height, int heightSize)
{
	int front = 0;
	int last = heightSize - 1;
	int max = 0;
	while (front < last)
	{
		int len = last - front;
		int lenmin = height[front] > height[last] ? height[last--] : height[front++];
		max =(max>(lenmin * len))?max:(lenmin*len);
	}
	return max;
}
int main(void)
{
	int height[] = { 1,8,6,2,5,4,8,3,7 };
	int heightSize = sizeof(height) / sizeof(height[0]);
	maxArea(height, heightSize);

}