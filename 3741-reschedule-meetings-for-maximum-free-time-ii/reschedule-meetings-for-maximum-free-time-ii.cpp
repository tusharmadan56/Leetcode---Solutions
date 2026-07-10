class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        multiset<int> ms ;

        int n = startTime.size();

        vector<int> temp;

            temp.push_back(startTime[0]);
            ms.insert(startTime[0]);
        

        for(int i=0;i<n-1;i++){
            temp.push_back(startTime[i+1]-endTime[i]);
            ms.insert(startTime[i+1]-endTime[i]);
        }

       
            temp.push_back(eventTime-endTime.back());
            ms.insert(eventTime-endTime.back());
        


        if(temp.size()==1){
            return temp.back();
        }

        if(temp.size()==2) return temp[0]+temp[1];

        // for(auto x:temp) cout<<x<<" ";
        // cout<<endl;

        int sz = temp.size();



        ms.erase(ms.find(temp[0]));
        ms.erase(ms.find(temp[1]));

        int ans = 0;

        for(int i=0;i<sz-1;i++){
            int val = -startTime[i]+endTime[i];

            auto it = ms.lower_bound(val);

            if(it!=ms.end()){
                ans = max(ans , temp[i]+temp[i+1]+val);

                
            }
            ms.insert(temp[i]);
            if(i+2<sz) ms.erase(ms.find(temp[i+2]));

            ans = max(ans, temp[i]+temp[i+1]);

            // for(auto x:ms) cout<<x<<" ";
            // cout<<endl;
        }

        return ans;








    }
};