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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node jo head ke pehle point karega
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Fast pointer ko n steps aage badhao
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        // Dono ko sath mein badhao jab tak fast last node par na pahunch jaye
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Target node ko delete/bypass karo
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Memory free karne ke liye
        
        // Naya head return karo
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};