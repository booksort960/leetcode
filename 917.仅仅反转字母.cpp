class Solution {
public:
    bool iFaiphabet(char& a)
    {
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
            return true;
        return false;
    }
    string reverseOnlyLetters(string s) {
        if (s.empty())
            return s;
        size_t begin = 0, end = s.length() - 1;
        while (begin < end)
        {
            while (begin < end && !iFaiphabet(s[begin]))
                begin++;
            while (begin < end && !iFaiphabet(s[end]))
                end--;
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
        return s;
    }
};