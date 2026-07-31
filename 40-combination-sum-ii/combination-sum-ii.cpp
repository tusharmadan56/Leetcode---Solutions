class Solution {
public:
    vector<vector<int>> fans ;
    int n ;

    void dfs(int i, int val , vector<int>& arr ,vector<int>& temp){
        if(val == 0 ){
            fans.push_back(temp);
            return ;

        }
        if(val<0) {
            return ;
        }
        if(i==arr.size()){
            return ;
        }

        temp.push_back(arr[i]);
        dfs(i+1 , val-arr[i] , arr , temp);
        temp.pop_back();

        int ind = i+1;

        while(ind<n && arr[ind]==arr[i]) ind++;


        dfs(ind , val , arr , temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int> temp;
        this->n = arr.size();
        dfs(0,target,arr,temp);


        return fans;


    }
};