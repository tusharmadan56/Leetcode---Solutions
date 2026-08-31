class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& arr) {
        vector<vector<int>> ans;

        int n = intervals.size();

        int a = arr[0] , b = arr[1];

        int i =0;

        while(i<n && intervals[i][1]<a){
            ans.push_back(intervals[i]);
            i++;
        }

        int s = a;
        int e = b;

        while(i<n && intervals[i][0]<=b){
            s = min(s , intervals[i][0]);
            e = max(e , intervals[i][1]);

            i++;
        }

        ans.push_back({s,e});

        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;



        return ans;


    }
};