uint32_t reverseBits(uint32_t n)
{
	int ret = 0;
	for (int i = 0; i < 32; i++)
	{
		ret = ret * 2 + n % 2;//相当于从最高位开始赋值而ret*2就是向左移动一位，而加n%2，是加余数，不是0就是1从最低位开始加
		n /= 2;//n/2就是右移一位
	}
	return ret;

}
uint32_t reverseBits(uint32_t n)
{
	unsigned int ret = 0;
	for (int i = 0; i < 32; i++)
	{
		ret = ret * 2 + n % 2;
		n /= 2;
	}
	return ret;

}