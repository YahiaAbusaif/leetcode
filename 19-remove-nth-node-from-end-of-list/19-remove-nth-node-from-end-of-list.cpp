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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* toRemove =head;
        ListNode* temp=head;
        int iter=0;
        while(temp)
        {
            iter++;
            if(iter>n+1)
            {
                toRemove=toRemove->next;
            }
            temp=temp->next;
        }
        if(toRemove == head && iter==n)
            return head->next;
        toRemove->next= toRemove->next->next;
        return head;
            
    }
};