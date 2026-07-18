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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr, *curr = head;
        while (curr){
            ListNode* t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* l = head,*t=head,*prev = nullptr,*ans = head;
        bool f = true;
        for(int i=0;l;i++){
            if(i%k == k-1){
                ListNode* e = l->next,*temp = nullptr;
                l->next = nullptr;
                temp = reverseList(t);
                if (prev) prev->next = temp;
                prev = t;
                t->next = e;
                l = t;
                t = e;
                if (f) {ans = temp; f=false;}
            }
            l = l->next;
        }
        return ans;
    }
};
