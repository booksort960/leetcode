class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (2 * sum + nums[i] == total)
                return i;
            sum += nums[i];
        }
        return -1;
    }
};