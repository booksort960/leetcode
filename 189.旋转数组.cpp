class Solution {
public:
    void _rotate(vector<int>& num, int start, int end)
    {
        while (start < end)
        {
            int tmp = num[start];
            num[start] = num[end];
            num[end] = tmp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        _rotate(nums, 0, nums.size() - k - 1);
        _rotate(nums, nums.size() - k, nums.size() - 1);
        _rotate(nums, 0, nums.size() - 1);
    }
};

////////////////////////////////////////////////////////////
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int a = 0;
        k %= nums.size();
        vector<int> num = nums;
        for (int i = 0; i < k; i++)
            num[a++] = nums[nums.size() - k + i];

        for (int i = 0; i < nums.size() - k; i++)
            num[a++] = nums[i];
        nums = num;//整个数组的赋值
    }
};