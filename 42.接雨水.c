int trap(int* height, int heightSize)//˫ָ�뷨
{
	int front = 0;
	int last = heightSize - 1;
	int frontmax = 0;
	int lastmax = 0;
	int vol = 0;
	while (front < last)
	{
		frontmax = (height[front] > frontmax) ? height[front] : frontmax;
		lastmax = (height[last] > lastmax) ? height[last] : lastmax;
		vol += frontmax - height[front];
		vol += lastmax - height[last];
		if (height[front] <= height[last])
		{
			front++;

		}
		else
			last--;
	}
	return vol;

}
int main(void)
{
	int height[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int heightSize = sizeof(height) / sizeof(height[0]);
	trap(height, heightSize);

}