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

 /******************* 2 pointers *******************/
class Solution {
public:
    // T:O(n), S:O(1)
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !head->next) return head;
        ListNode* header = new ListNode(0);
        header->next = head;
        ListNode* p = header;
        ListNode* q = head->next;

        while(q ){
            ListNode* tmp = p->next;
            p->next = q;
            p=q->next;
            q->next = tmp;
            tmp->next = p;
            if(p==0) break;
            q=p->next; p=tmp;
        }

        p = header; header = header->next;
        delete p;
        return header;
    }
};

/******************* 1 pointer *******************/
class Solution {
public:
    // T:O(n), S:O(1)
    ListNode* swapPairs(ListNode* head) {

        ListNode* header = new ListNode(0);
        header->next = head;
        ListNode* walker = header;

        while(walker != 0 && walker->next != 0 && walker->next->next != 0){
            ListNode* temp = walker->next;
            ListNode* temp2 = walker->next->next;

            temp->next = temp2->next;
            walker->next = temp2;
            walker->next->next = temp;

            walker = walker->next->next;
        }

        walker = header;
        header = header->next;
        delete(walker);

        return header;
    }
};
