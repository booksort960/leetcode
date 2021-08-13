class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        ret.resize(0);
        size_t len = max(a.size(), b.size());
        int i = a.size() - 1;
        int j = b.size() - 1;
        char atmp = '0';
        char btmp = '0';
        int carry = 0;
        for (int t = len - 1; t >= 0; t--, i--, j--)
        {
            atmp = i < 0 ? '0' : a[i];
            btmp = j < 0 ? '0' : b[j];
            if (atmp - '0' + btmp - '0' + carry >= 2)
            {
                ret += atmp - '0' + btmp + carry - 2;
                carry = 1;
            }
            else
            {

                ret += atmp - '0' + btmp + carry;
                carry = 0;
            }
            if (t == 0 && carry == 1)
            {
                ret += '1';
            }

        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};