uint32_t reverseBits(uint32_t n)
{
	int ret = 0;
	for (int i = 0; i < 32; i++)
	{
		ret = ret * 2 + n % 2;//�൱�ڴ����λ��ʼ��ֵ��ret*2���������ƶ�һλ������n%2���Ǽ�����������0����1�����λ��ʼ��
		n /= 2;//n/2��������һλ
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