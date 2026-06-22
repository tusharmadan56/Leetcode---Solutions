class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> mp;
        for(auto x:text) mp[x]++;

        int ans = 1e9;

        string str = "balon";

        for(char x:str){
            if(x=='l' || x=='o') mp[x]/=2;

            ans = min(ans , mp[x]);
            //cout<<mp[x]<<endl;
           
        }

        return max(0,ans);
    }
};