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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* head1=head;
        ListNode* head2=head->next;
        head=head2;
        head1->next= head2->next;
        head2->next=head1;
        head2=head1,head1=head1->next;
        while(head1&&head2)
        {
            if(head1->next==NULL)
                return head;
            head2->next=head1->next;
            ListNode*next = head2->next->next;
            head2->next->next=head1;
            head1->next=next;
            head2=head1;
            head1=head1->next;
            
        }
        return head;
    }
};