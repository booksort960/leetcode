#include <stdio.h>
#include <string.h>
void replaceSpace(char* str, int length)
{
    char* p = str;
    int num = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if (*(p + i) == ' ')
            num++;
    }
    int len = length +2 * num;
    while (length)
    {
        if (p[length] == ' ')
        {
            p[len--] = '0';
            p[len--] = '2';
            p[len--] = '%';
            length--;
        }
        p[len--] = p[length--];
    }
}
int main(void)
{
    char arr[100] = "we are happy";
    replaceSpace(arr, strlen(arr));
    printf("%s",arr);
    return 0;
}