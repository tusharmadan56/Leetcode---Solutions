class Solution {
public:
    vector<int> fun(vector<int>& nums,int k){
        int n  = nums.size();
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()<nums[i] && (n-i)+st.size()-1>=k){
                st.pop();
            }
            st.push(nums[i]);
        }

        while(st.size()>k) {
            st.pop();
        }

        vector<int> fans ;

        while(!st.empty()) {
            fans.push_back(st.top());
            st.pop();
        }

        reverse(fans.begin(),fans.end());

        return fans;


    }

    int dfs(vector<int>& v1,vector<int>& v2,int i,int j){
        int n = v1.size() , m = v2.size();
        while(i<n && j<m){
            if(v1[i]==v2[j]) {
                i++;
                j++;
            }
            else if(v1[i]>v2[j]) {
                return 1;
            }
            else{
                return 2;
            }
        }

        if(i==n) return 2;
        return 1;
    }

    vector<int> merge(vector<int>& v1,vector<int>& v2){
        int n = v1.size() , m = v2.size();

        int i=0,j=0;

        vector<int> fans;

        while(i<n && j<m){
            if(v1[i]>v2[j]){
                fans.push_back(v1[i]);
                i++;
            }
            else if(v1[i]==v2[j]){
                fans.push_back(v1[i]);
                if(dfs(v1,v2,i,j)==1){
                    i++;
                }
                else j++;
            }
            else fans.push_back(v2[j++]);
        }

        while(i<n) fans.push_back(v1[i++]);
        while(j<m) fans.push_back(v2[j++]);

        return fans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size() , m  = nums2.size();


        vector<int> fans;

        for(int i=min(k,n);i>=0;i--){
            int rem = k-i;
            if(rem>m) break;

            vector<int> v1 = fun(nums1,i);
            vector<int> v2 = fun(nums2,rem);

            fans = max(fans , merge(v1,v2));
        }

        return fans;
    }
};