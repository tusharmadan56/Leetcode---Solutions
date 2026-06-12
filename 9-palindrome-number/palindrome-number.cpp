class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;

        string str = to_string(x);
        string temp = str;
        reverse(str.begin(),str.end());

        return str==temp;

    }
};