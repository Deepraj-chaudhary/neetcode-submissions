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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1, *t2 = list2, *ans = list1;
        if(!t1) return t2;
        if(!t2) return t1;
        if(list1->val>list2->val) {
            t1 = list2;
            t2 = list1;
            ans = list2;
        }
        while(t2){
            ListNode* t = t1->next, *temp = t2->next;
            while(t && t->val <= t2->val){
                t = t->next;
                t1 = t1->next;
            }
            t1->next = t2;
            t2->next = t;
            t1 = t2;
            t2 = temp;
        }
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0) return nullptr;
        if (lists.size()==1) return lists[0];

        for(int i = 1; i<lists.size(); i++){
            lists[0] = mergeTwoLists(lists[0],lists[i]);
        }        

        return lists[0];
    }
};
