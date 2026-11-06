#include <iostream>
#include <unordered_set>
using namespace std; 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * Detects if a linked list contains a cycle.
     * Uses a hash set to track visited nodes.
     *
     * @param head: pointer to the head of the linked list
     * @return: true if cycle exists, false otherwise
     */
    bool hasCycle(ListNode* head) {
        // Hash set to store visited node addresses
        unordered_set<ListNode*> visitedNodes;

        // Traverse the linked list
        ListNode* current = head;
        while (current != nullptr) {
            // Check if current node has been visited before (cycle detected)
            if (visitedNodes.count(current) > 0) {
                return true;
            }

            // Mark current node as visited
            visitedNodes.insert(current);

            // Move to next node
            current = current->next;
        }

        // No cycle found after traversing entire list
        return false;
    }
};


