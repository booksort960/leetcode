//�Ǳ���
//�Ǳ���������32λ��ÿһλ�Ƿ���1����1�ĸ���*0�ĸ��������Ƕ���ÿ�������������λ�ϵĺ������롣�ٱ���32λ����
int totalHammingDistance(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < 32; i++)
    {
        int n = 0;
        for (int j = 0; j < numsSize; j++)
        {
            n += ((nums[j] >> i) & 1);
        }
        sum += n * (numsSize - n);
    }
    return sum;
}

//������
//�����޷�������ʱ��
int HammingDistance(int x, int y)
{
    int i = 0;
    int tmp = x ^ y;
    while (tmp)
    {
        i += tmp & 1;
        tmp >>= 1;
    }
    return i;
}
int totalHammingDistance(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            sum += HammingDistance(nums[i], nums[j]);
        }
    }
    return sum;
}
