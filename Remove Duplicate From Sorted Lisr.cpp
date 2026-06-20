/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Base case: if the list is empty or has only one node
        if (!head) return nullptr;

        ListNode* current = head;

        // Traverse the list until the second to last node
        while (current && current->next) {
            if (current->val == current->next->val) {
                // Duplicate found! Save reference to delete it and free memory
                ListNode* duplicate = current->next;
                current->next = current->next->next; // Link past the duplicate
                delete duplicate;                    // Free the unlinked node
            } else {
                // Distinct value, advance the pointer
                current = current->next;
            }
        }

        return head;
    }
};