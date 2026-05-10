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
    void reorderList(ListNode* head) {
        deque<ListNode* > order;
        ListNode* curr=head;
        while(curr){
            order.push_back(curr);
            curr=curr->next;
        }
        ListNode d(0);
        curr=&d;
        while(!order.empty()){
            curr->next=order.front();
            order.pop_front();
            curr=curr->next;
            if(!order.empty()){
                curr->next=order.back();
                order.pop_back();
                curr=curr->next;
            }
        }
        curr->next=nullptr;
        head=d.next;
    }
};
