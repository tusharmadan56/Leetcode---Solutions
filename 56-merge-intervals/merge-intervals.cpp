class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end());

        ans.push_back(intervals[0]);

        for(int i=1;i<(int)intervals.size();i++){
            int val = ans.back().back();

            if(intervals[i][0]>val){
                ans.push_back(intervals[i]);
            }
            else{
                if(intervals[i][1]>val){
                    ans.back().back() = intervals[i][1];
                }
            }
        }

        return ans;
    }
};