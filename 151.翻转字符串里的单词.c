char* reverseWords(char* s) {
    int len = strlen(s);
    char* arr = (char*)malloc(sizeof(char) * (len + 1));
    int i = 0;
    int dest = len - 1;//���ַ���β����ʼ����
    while (dest >= 0)
    {
        if ((dest == 0 && s[0] != ' ') || s[dest] == ' ' && s[dest + 1] != ' ' && s[dest + 1] != '\0')//Ԫ��Ϊ���ʵ�����
        {
            if (i != 0)
                arr[i++] = ' ';
            int last = dest + 1;
            if (dest == 0 && s[0] != ' ')//�����������ı�last��ֵ
            {
                last = dest;
            }
            while (s[last] != ' ' && s[last] != '\0')//�����ʿ��������������
            {
                arr[i++] = s[last++];
            }
        }
        dest--;
    }
    arr[i] = '\0';//�ַ�������
    return arr;
}