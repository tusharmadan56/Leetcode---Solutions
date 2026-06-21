class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();

        unordered_map<int,int> mp;

        for(auto x:costs) mp[x]++;

        int ma = *max_element(costs.begin(),costs.end());

        int ans =0;

        for(int i=1;i<=ma;i++){
            int cnt = mp[i];
            int gg = coins/i;
            if(gg>=cnt) {
                ans+=cnt;
                coins-=cnt*i;
            }

            else {
                ans+=gg;
                coins -= gg*i;
            }
        }
        return ans;
    }
};