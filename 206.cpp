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

/********************** Recursive Approach (no help) **********************/
 class Solution {
 public:
     ListNode* reverseList(ListNode* head)
     {
         /*
             reverse a linked list, remember to use prev, cur 2 ptr.
         */
         if (!head||!head->next) return head;
         ListNode *p=reverseList(head->next);
         head->next->next=head;
         head->next=0;
         return p;
     }
 };

/********************** Recursive Approach (with help) **********************/
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        /*
            reverse a linked list, remember to use prev, cur 2 ptr.
        */
        return help(0,head);
    }

    ListNode* help(ListNode *prev, ListNode *cur)
    {
        if (!cur) return prev;
        ListNode *next=cur->next;
        cur->next = prev;
        return help(cur, next);
    }
};

/********************** Iterative Approach **********************/
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        /*
            reverse a linked list, remember to use prev, cur 2 ptr.
        */
        ListNode *prev=0, *cur=head;
        while (cur) {
            ListNode *next=cur->next;
            cur->next=prev;
            prev=cur; cur=next;
        }
        return prev;
    }
};
