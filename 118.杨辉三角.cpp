class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        v.resize(numRows);
        for (int i = 0; i < numRows; i++)
        {
            v[i].resize(i + 1);
            v[i][0] = v[i][v[i].size() - 1] = 1;
            for (int j = 0; j < v[i].size(); j++)
            {
                if (j != 0 && j != v[i].size() - 1)
                {
                    v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
                }
            }
        }
        return v;
    }
};