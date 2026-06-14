/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int i=0;
        vector<int> temp;

        while(head){
            int val = head->val;
            temp.push_back(val);
            head = head->next;


        }

        for(auto x:temp) cout<<x<<" ";

        int n = temp.size();
        int ans =0;

        for(int i=0;i<n/2;i++){
            ans = max(ans , temp[i]+temp[n-i-1]);
        }
        return ans;
    }
};