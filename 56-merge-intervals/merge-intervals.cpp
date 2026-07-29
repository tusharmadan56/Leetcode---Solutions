class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> temp;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]>ans.back().back()){
                ans.push_back(intervals[i]);
            }
            else {
                ans.back().back() = max(ans.back().back(),intervals[i][1]);
            }
           
        }
        return ans;
    }
};