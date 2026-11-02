#include <iostream>
using namespace std

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (true) {
            // find the k-th node of this group
            ListNode* kth = prev;
            for (int i = 0; i < k && kth; i++) kth = kth->next;
            if (!kth) break;               // fewer than k left: leave as is

            ListNode* groupNext = kth->next;
            ListNode* cur = prev->next;
            ListNode* p = groupNext;       // reversed part links to the next group

            while (cur != groupNext) {
                ListNode* nxt = cur->next;
                cur->next = p;
                p = cur;
                cur = nxt;
            }

            ListNode* tail = prev->next;   // old first node is now the group's tail
            prev->next = kth;              // connect previous part to new group head
            prev = tail;
        }
        return dummy.next;
    }
};