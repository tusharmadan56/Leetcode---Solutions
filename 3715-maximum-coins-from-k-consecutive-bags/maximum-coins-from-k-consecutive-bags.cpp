class Solution {
public:
    #define ll long long
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(),coins.end());

        vector<ll> temp;
        temp.push_back(0);

        ll ans =0;

        map<ll,ll> mp;

        for(auto &v:coins){
            temp.push_back(v[0]);
            temp.push_back(v[1]);

            mp[v[0]]=v[2];
            mp[v[1]]=v[2];
        }

        int j=0;

        vector<ll> pref(temp.size());

        pref[0] = 0;

        for(int i=1;i<temp.size();i++){
            if(i%2!=0){
                pref[i] = pref[i-1]+coins[j][2];
            }
            else{
                pref[i] = pref[i-2]+(temp[i]-temp[i-1]+1)*coins[j][2];
                j++;
            }
        }

        // for(auto x:temp){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        j=0;

        int n = temp.size();


        for(int i=1;i<temp.size();i++){
            if(i%2!=0){
                ll val = temp[i]+k-1;

                int it = lower_bound(temp.begin(),temp.end(),val)  -temp.begin();
                if(it==n){
                    ll fans = pref[it-1]-pref[i-1];
                    ans = max(ans , fans);
                    //cout<<fans<<" ";
                    continue;
                }
                ll gg = temp[it];
                

                if(gg==val){
                    if(it%2!=0){
                        ll fans = pref[it]-pref[i-1];
                        ans = max(ans , fans);
                        //cout<<fans<<" ";
                    }
                    else{
                        ll fans = pref[it]-pref[i-1]-(gg-val)*mp[temp[it]];
                        //cout<<fans<<" ";
                        ans = max(ans , fans);
                    }
                }
                else{
                    if(it%2!=0){
                        ll fans = pref[it-1]-pref[i-1];
                        //cout<<fans<<" ";
                        ans = max(ans , fans);
                    }
                    else{
                        ll fans = pref[it]-pref[i-1]-(gg-val)*mp[temp[it]];
                        //cout<<fans<<" ";
                        ans = max(ans , fans);
                    }
                }
            }
            else {
                ll val = temp[i]-k+1;

                ll it = lower_bound(temp.begin(),temp.end(),val)  -temp.begin();
                if(it==0){
                    
                    continue;
                }
                ll gg = temp[it];
                

                if(gg==val){
                    if(it%2!=0){
                        ll fans = pref[i]-pref[it-1];
                        //cout<<fans<<" ";
                        ans = max(ans , fans);
                    }
                    else{
                        ll fans = pref[i]-pref[it]+mp[temp[it]];
                        //cout<<fans<<" ";
                        ans = max(ans , fans);
                    }
                }
                else{
                    if(it%2!=0){
                        ll fans = pref[i]-pref[it-1];
                        //cout<<fans<<" ";
                        ans = max(ans , fans);
                    }
                    else{
                        ll fans =pref[i]-pref[it]+(gg-val+1)*mp[temp[it]];;
                        //cout<<fans<<" ";
                        ans = max(ans , fans);
                    }
                }
                j++;
            }
        }
        return ans;
    }
};