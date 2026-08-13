class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int,vector<int> , greater<int>> pq1;
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq2;


        vector<pair<int,int>> v;
        for(int i=0;i<(int)times.size();i++){
            v.push_back({times[i][0] , i});
        }

        sort(v.begin(),v.end());
        int n = times.size();


        for(int i=0;i<n;i++){
            pq1.push(i);
        }

        for(auto [x,y]:v){
            while(!pq2.empty() && pq2.top().first<=x){
                pq1.push(pq2.top().second);
                pq2.pop();
            }

            int ans = pq1.top();
            pq1.pop();

            pq2.push({times[y][1],ans});

            if(y==targetFriend){
                return ans;
            }
        }

        return -1;

    }
};