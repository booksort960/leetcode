class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        size_t begin = 0;
        size_t end = nums.size() - 1;
        while (begin < end)
        {
            while (begin < end && nums[end] % 2 == 1)
                end--;
            while (begin < end && nums[begin] % 2 == 0)
                begin++;
            if (nums[begin] % 2 == 1 && nums[end] % 2 == 0)
            {
                swap(nums[begin], nums[end]);
            }

        }
        return nums;
    }
};