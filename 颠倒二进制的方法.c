//uint32_t reverseBits(uint32_t n) 
//{
//	char* head = (char*)(&n);
//	char* end = head + 31;
//	while (head < end)
//	{
//		char ch = *(head);
//		*(head) = *(end);
//		*(end) = ch;
//		head++;
//		end--;
//	}
//	return n;
//}
uint32_t reverseBits(uint32_t n)
{
	int ret = 0;
	for (int i = 0; i < 32; i++)
	{
		ret |= (n & 1) << (31 - i);
		n >>= 1;
	}
	return ret;

}