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
/*
     T:O(n), S:O(n)
     2 pass solution with a hashmap, key, val are index and listnode
     respectively.
     ----------------
     3 pass:
         separate 2 lists;
         invert second one
         merge 2 lists
     T:O(n),S:O(1)
     ----------------
     Think about 1 pass solution, or use S:O(1) to solve it.
     use a dfs to get tail then construct the list, stop in the middle.
     1 pass, T:O(n) S:O(n) (recursive depth)

 */

/******* Second Visit *******/
 /*
    backtracking from tail ptr and forward tracking from head ptr.
    it could be implemented by iterative/recursive.
    T:O(n)/S:O(n)
    ----------------
    iterative:
    stack -> 1 2 3 4
                 ^
    stack -> 1 2 3 4 5
                 ^
    stop criteria pt->next==p2 || p1==p2
    ----------------
    Remember to inverse second part then merge
    T:O(n) 3 pass / S:O(1)
*/
class Solution {
public:
    void reorderList(ListNode* head)
    {
        if (!head) return;
        stack<ListNode*> s;
        ListNode *tail=head;
        while (tail) { s.push(tail); tail=tail->next; }
        tail=head;
        while (tail->next!=s.top()&&tail!=s.top()) {
            ListNode* next=tail->next;
            tail->next=s.top(); s.pop();
            tail->next->next=next;
            tail=next;
        }
        if (tail!=s.top()) {
            tail->next=s.top(); s.pop();
            tail=tail->next;
        }
        tail->next=0;
        return;
    }
};

class Solution {
public:
    void reorderList(ListNode* head)
    {
        ListNode *slow=head,*fast=head;
        int n=0;
        while(fast&&fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            n++;
        }
        ListNode *prev=0, *cur=slow;
        while(cur){
            ListNode *next=cur->next;
            cur->next=prev;
            prev=cur; cur=next;
        }
        cur=head;
        for (int i=0; i<n; ++i) {
            ListNode *next=cur->next;
            cur->next=prev;
            prev=prev->next;
            if (cur->next->next) cur->next->next=next;
            cur=next;
        }
    }
};

/******* First Visit *******/
class Solution {
public:
    ListNode *header, *tail;
    void reorderList(ListNode* head)
    {
        if(!head) return;
        header=head; tail=head;
        getTail(head);
    }

    void getTail(ListNode *node)
    {
        if (!node) return;
        getTail(node->next);
        if (!tail) return;
        if (tail==node||tail->next==node){
            if (tail->next==node) {tail->next=node;node->next=0;}
            else tail->next=0;
            tail=0;
            return;
        }

        ListNode *next=tail->next;
        tail->next=node;
        node->next=next;
        tail=next;
        return;

    }
};
