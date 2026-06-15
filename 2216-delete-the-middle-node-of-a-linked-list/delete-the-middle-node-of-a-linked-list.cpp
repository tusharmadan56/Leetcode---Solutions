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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast->next){
           slow->next = slow->next->next; 
        }
        else{
            ListNode* temp = head;
            while(temp->next && temp->next!=slow){
                temp=temp->next;
            }
                if(!temp->next) return nullptr;
            temp->next = temp->next->next;
        }

        return head;


    }
};