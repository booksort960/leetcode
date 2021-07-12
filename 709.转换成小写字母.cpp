#include <iostream>
#include <string>
int main(void)
{
	int i = 0;
	std::string s = "Hello";
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		i++;
	}
	std::cout << s;
	return 0;
}