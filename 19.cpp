/***** Fifth Visit *****/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *header=new ListNode();
        header->next=head;
        ListNode *l=header, *r=header;
        while (n--) r=r->next;
        while (r->next) {
            l=l->next;
            r=r->next;
        }
        l->next=l->next->next;
        return header->next;

    }
};

/***** Fourth Visit *****/
/*
    1->2->null
    ^.    ^
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=head, *fast=head;
        for (int i=0; i<n; ++i)
            fast=fast->next;
        while (fast&&fast->next) {
            slow=slow->next;
            fast=fast->next;
        }
        if (fast) {
            slow->next=slow->next->next;
            return head;
        }
        else return head->next;
    }
};

/***** Third Visit *****/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *l=head,*r=head;
        while(n>=0) {
            if (!r) return head->next;
            r=r->next; n--;
        }
        while (r) {
            r=r->next;
            l=l->next;
        }
        r=l->next;
        l->next=r->next;
        delete r;
        return head;
    }
};

/***** Second Visit *****/
/*
    delete Nth node from end in one pass.
    use slow/fast ptr solution.
    **Note that n will always be valid**
    T:O(n)/S:O(1)
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (n==0) return head;
        ListNode *header=new ListNode(0);
        header->next=head;
        ListNode *slow=header, *fast=header;
        for(int i=0; i<n; ++i) fast=fast->next;
        ListNode *prev=0;
        while(fast) {
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        prev->next=slow->next;
        delete slow;
        head=header->next;
        delete header;
        return head;
    }
};

 /***** First Visit *****/
class Solution {
public:
    // T:O(n), S:O(n)
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (!head ) return head;

        ListNode* header = head;
        unordered_map<int, ListNode*> table;
        int counter = 0;
        while(head) {
            table[counter++] = head;
            head = head->next;
        }
        if(table.find(counter-n-1)==table.end()) {
            ListNode* cur=table[counter-n];
            header=cur->next;
            delete cur;
        }
        else {
            ListNode* prev = table[counter-n-1];
            ListNode* cur = table[counter-n];
            prev->next = cur->next;
            delete cur;
        }
        return header;
    }
};

/***************** Two pointers *****************/
/***************** Use header pointers for edge case *****************/

class Solution {
// T:O(n), S:O(1)
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (!head ) return head;
        ListNode* header = new ListNode(0);
        header->next=head;

        ListNode* first=header;
        ListNode* second=header;
        for (int i=0; i<=n; ++i)
            first = first->next;
        while(first) {
            second=second->next;
            first=first->next;
        }
        ListNode* tmp = second->next;
        second->next = second->next->next;
        delete tmp;
        tmp = header;
        header=header->next;
        return header;
    }
};
