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

/***** Second Visit *****/
class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode *h1=new ListNode(),*h2=new ListNode();
        ListNode *p=head,*h1p=h1,*h2p=h2;
        while(p){
            if (p->val<x) {h1p->next=p; h1p=h1p->next;}
            else {h2p->next=p; h2p=h2p->next;}
            p=p->next;
        }
        h1p->next=h2->next;
        h2p->next=0;
        return h1->next;
    }
};

/***** First Visit *****/
class Solution {
public:
    // T:O(n)
    ListNode* partition(ListNode* head, int x)
    {
        /*
        2 pointers, say smaller, larger
        smaller->next=larger
        try to do it in one pass
        */
        ListNode *s = new ListNode(0); // smaller
        ListNode *l = new ListNode(0); // larger
        ListNode *st=s,*lt=l;

        while(head) {
            if (head->val<x) {st->next=head; st=st->next;}
            else {lt->next=head; lt=lt->next;}
            head=head->next;
        }
        st->next=l->next;
        lt->next=0;
        lt=s; s=s->next;
        delete(lt); delete(l);
        return s;
    }
};
