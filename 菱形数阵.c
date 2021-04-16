#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int input,num;
	scanf_s("%d", &input);
	int ROW, COL;
	int max = input * 2 - 1;
	for (int y = 0; y <max; ++y)
	{
		for (int x = 0; x < max-abs(y+1-input); ++x)
		{ 
			num = input-abs(y + 1 - input) -abs(x+1-input);//abs(y)负责每行空白处的值，也就是每列的最大值 
			if(num<=0)
				printf(" ");
			else
				printf("%d", num);
		}
		printf("\n");
	}
	return 0;
}