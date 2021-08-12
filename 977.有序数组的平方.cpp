class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v(nums);
        size_t begin = 0, end = nums.size() - 1;
        int i = v.size() - 1;
        while (i >= 0)
        {
            size_t begin_num = pow(nums[begin], 2);
            size_t end_num = pow(nums[end], 2);
            if (begin_num > end_num)
            {
                v[i] = begin_num;
                begin++;
            }
            else
            {
                v[i] = end_num;
                end--;
            }
            i--;
        }
        return v;
    }
};