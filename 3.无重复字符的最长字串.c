#include <stdio.h>
int lengthOfLongestSubstring(char* s)//»¬¶¯´°¿Ú
{
	if (*s == '\0')
		return 0;
	int front = 0;
	int last = 1;
	int max = 0;
	
	int len = strlen(s);
	while (s[front] != '\0'&&front<last)
	{
		int flag = 1;
		last = (last < len) ? last : len - 1;
		int f = front;
		while (f < last)
		{
			if (s[f] == s[last])
			{
				flag = 0;
				break;
			}
			else
			{
				flag = 1;
			}
			f++;
		}
		if (flag == 0)
		{
			front = f + 1;
		}
		
		
		int num = last - front+1;
		max = (num > max) ? num : max;
		
		if (s[last+1]=='\0')
		{
			
			front++;
		}
		last++;
	}
	return max;
}
int main(void)
{
	lengthOfLongestSubstring("bdb");

	return 0;
}