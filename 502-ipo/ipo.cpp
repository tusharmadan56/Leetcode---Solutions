class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;

        vector<pair<int,int>> v;
        int n  = profits.size();
        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }

        sort(v.begin(),v.end(),[&](const pair<int,int> a, const pair<int,int> b){
            
            return a.first<b.first;
        });

        int i=0;

        while( k>0){
            while(i<n && w>=v[i].first){
                pq.push(v[i].second);
                i++;
            }


            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
                k--;
            }
            else break;
            


           

        }
        return w;
    }
};