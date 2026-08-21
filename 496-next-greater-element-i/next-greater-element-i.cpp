class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;

        int n = nums2.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            int gg = -1;
            if(st.size()){
                gg = st.top();
            }

            mp[nums2[i]]=gg;

            st.push(nums2[i]);
        }

        for(int i=0;i<(int)nums1.size();i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};