//非暴力
//非暴力，计算32位上每一位是否有1，有1的个数*0的个数，就是对于每个数，这给比特位上的汉明距离。再遍历32位即可
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

//暴力法
//大数无法处理，超时了
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
