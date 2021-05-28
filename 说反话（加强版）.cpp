//#include <iostream>
//int main(void)
//{
//    int a = 0;
//    char ch;
//    char arr1[500000];
//    char arr2[500000];
//    while ((ch = getchar()) != '\n')
//    {
//        arr1[a++] = ch;
//    }
//    arr1[a] = '\0';
//    int len = strlen(arr1);
//    int i = 0;
//    int dest = len - 1;
//    int last = 0;
//    int flag = 0;
//    while (dest >= 0)
//    {
//        if (arr1[dest] == ' ' && arr1[dest + 1] != ' '&&arr1[dest+1]!='\0'||(dest == 0 && arr1[0] != ' '))
//        {
//            int last = dest + 1;
//            if (dest == 0 && arr1[0] != ' ')
//            {
//                last = dest;
//            }
//            while (arr1[last] != ' ' && arr1[last] != '\0')
//            {
//                arr2[i++] = arr1[last++];
//            }
//            if (dest != 0 || arr1[last] != '\0')
//                arr2[i++] = ' ';
//        }
//        dest--;
//        /*if (arr1[dest] != ' ')
//        {
//            flag = 0;
//        }
//        if (flag == 0 && (arr1[dest] == ' '||dest==0))
//        {
//            last = dest + 1;
//            if (dest == 0)
//            {
//                last = dest;
//            }
//            while (arr1[last] != ' ' && arr1[last] != '\0')
//            {
//                arr2[i++] = arr1[last++];
//            }
//            if (dest != 0)
//                arr2[i++] = ' ';
//            flag = 1;
//        }*/
//        
//    }
//    arr2[i] = '\0';
//    std::cout<<arr2;
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//int main(void)
//{
//    int a = 0;
//    char ch;
//    char arr[500000];
//    while ((ch = getchar()) != '\n')
//    {
//        arr[a++] = ch;
//    }
//    arr[a] = '\0';
//    int len = strlen(arr);
//    int i = 0;
//    int dest = len - 1;
//    int last = 0;
//    int flag = 0;
//    while (dest >= 0)
//    {
//        if (arr[dest] == ' ' && arr[dest + 1] != ' ')
//        {
//            int last = dest + 1;
//            while (arr[last] != '\0' && arr[last] != ' ')
//            {
//                printf("%c", arr[last]);
//                last++;
//            }
//            printf(" ");
//        }
//        dest--;
//    }
//    return 0;
//}
#include <iostream>
#include <cstring>
int main(void)
{
    int a = 0;
    char ch;
    char arr1[500001];
    char arr2[500001];
    while ((ch = getchar()) != '\n')
    {
        arr1[a++] = ch;
    }
    arr1[a] = '\0';
    int len = strlen(arr1);
    int i = 0;
    int dest = len - 1;
    while (dest >= 0)
    {
        if (arr1[dest] == ' ' && arr1[dest + 1] != ' ' && arr1[dest + 1] != '\0' || (dest == 0 && arr1[0] != ' '))
        {
            if (i != 0)
                arr2[i++] = ' ';
            int last = dest + 1;
            if (dest == 0 && arr1[0] != ' ')
            {
                last = dest;
            }
            while (arr1[last] != ' ' && arr1[last] != '\0')
            {
                arr2[i++] = arr1[last++];
            }
        }
        dest--;
    }
    arr2[i] = '\0';
    std::cout << arr2 << std::endl;
    return 0;
}