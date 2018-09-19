class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        string str_x=to_string(x);
        string str_re=str_x;
        ::reverse (str_x.begin(),str_x.end());
        if(str_re==str_x)
        {
            return true;
        }
        return false;
    }
};