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
    static bool cmp(ListNode* one, ListNode* two){
        return one->val>two->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, decltype(&cmp)> minHeap(cmp);
        for(int i=0;i<lists.size();i++){
            ListNode* curr=lists[i];
            while(curr){
                minHeap.push(curr);
                curr=curr->next;
            }
        }
        ListNode d(0);
        ListNode* curr=&d;
        while(!minHeap.empty()){
            curr->next=minHeap.top(); minHeap.pop();
            curr=curr->next;
        }
        curr->next=nullptr;
        return d.next;
    }
    
};
