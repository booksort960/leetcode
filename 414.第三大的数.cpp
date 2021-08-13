class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int max = nums[0];
        size_t j = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
                continue;
            if (nums[i] < max)
            {
                max = nums[i];
                j++;
            }
            if (j == 3)
            {
                return max;
            }
        }
        return nums[0];
    }
};