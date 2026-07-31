class Solution {
public: 
    set<vector<int>> fans;
    int n;
    void dfs(int i,vector<int>& temp,vector<int>& nums){
        if(i==n){
            //sort(temp.begin(),temp.end());
            fans.insert(temp);
            return ;
        }

        temp.push_back(nums[i]);
        dfs(i+1 , temp,nums);
        temp.pop_back();
        dfs(i+1,temp,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        this->n = nums.size();
        vector<int> temp;
        sort(nums.begin(),nums.end());
        dfs(0,temp,nums);

        //vector

        return vector<vector<int>>(fans.begin(),fans.end());
    }
};