class Solution {
public:
    #define ll long long 
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<int> v;
        for(auto &temp:intervals){
            v.push_back(temp[0]);
        }

        sort(v.begin(),v.end());
        sort(intervals.begin(),intervals.end());

        ll fans = 0;

        int i =0 ;

        for(auto &temp : intervals){
            ll c1 = upper_bound(v.begin()+i,v.end(),temp[1]) - v.end();
            ll c2 = lower_bound(v.begin()+i,v.end(),temp[0]) - v.end();

            //cout<<c1<<" "<<c2<<endl;

            fans +=  c1 - c2-1;
            i++;
        }

        return fans;
    }
};