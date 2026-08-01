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
    ListNode* rev(ListNode* head){
        if(!head) return nullptr;

        ListNode* temp = rev(head->next);
        if(head->next){
            head->next->next = head;
            head->next = NULL;
        }
        else{
            return head;
        }

        return temp;
    }
    ListNode* reverseList(ListNode* head) {
        return rev(head);
    }
};