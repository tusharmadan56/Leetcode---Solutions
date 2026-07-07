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

        if(!head || !head->next) return head;

        ListNode* temp = rev(head->next);

        head->next->next = head;

        head->next = NULL;

        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        int lol = k-1;

        ListNode* temp2 = head;

        ListNode* temp3 = new ListNode(-1);
        ListNode* dum = temp3;

        while(temp){
            if(lol==0 ){
                lol=k-1;

                ListNode* nex = temp->next;
                temp->next = NULL;

                ListNode* gg = rev(temp2);

                

                temp3->next = gg;
                temp2->next = nex;

                temp3=temp2;

                temp2 = nex;
                temp=nex;

                //return dum->next;


                //cout<<temp->val<<" "<<temp2->val<<" "<<temp3->val<<endl;
                
            }
            else{
                lol--;
                temp=temp->next;

            }


        }
        
        return dum->next;
    }
};