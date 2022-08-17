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
    vector<ListNode*> ans;
    
    
    void inserToArray(ListNode* head){
        if(head == NULL){
            return;
        }
        inserToArray(head->next);
        int index = head->val + 10000;
        head->next = ans[index];
        ans[index] = head;
        
    }
    
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ans = vector<ListNode*>(20001,NULL);
        for(int index=0;index<lists.size();index++){
            inserToArray(lists[index]);
        }
        ListNode* head = NULL;
        ListNode* curr;
        for(int index=0;index<20001;index++){
            if(ans[index]!=NULL){
                if(head==NULL)
                    head=ans[index];
                else
                    curr->next = ans[index];
                curr=ans[index];
                while(curr->next!=NULL){
                    curr=curr->next;
                }
            }
        }
        return head;
    }
};