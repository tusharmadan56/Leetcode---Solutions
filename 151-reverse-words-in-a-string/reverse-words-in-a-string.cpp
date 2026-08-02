class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        stringstream ss(s);

        string word;

        string fans="";

        while(ss>>word){
            reverse(word.begin(),word.end());
            fans+=word;
            fans+=" ";
        }
        fans.pop_back();
        return fans;
    }
};