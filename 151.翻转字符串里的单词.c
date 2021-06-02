char* reverseWords(char* s) {
    int len = strlen(s);
    char* arr = (char*)malloc(sizeof(char) * (len + 1));
    int i = 0;
    int dest = len - 1;//从字符串尾部开始遍历
    while (dest >= 0)
    {
        if ((dest == 0 && s[0] != ' ') || s[dest] == ' ' && s[dest + 1] != ' ' && s[dest + 1] != '\0')//元素为单词的条件
        {
            if (i != 0)
                arr[i++] = ' ';
            int last = dest + 1;
            if (dest == 0 && s[0] != ' ')//满足条件，改变last的值
            {
                last = dest;
            }
            while (s[last] != ' ' && s[last] != '\0')//将单词拷贝到输出数组中
            {
                arr[i++] = s[last++];
            }
        }
        dest--;
    }
    arr[i] = '\0';//字符串结束
    return arr;
}