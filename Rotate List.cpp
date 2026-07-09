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
#include <iostream>
using namespace std;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        
        // find length and tail
        int n = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            n++;
        }
        
        k = k % n;
        if(k == 0) return head;
        
        // make it circular
        tail->next = head;
        
        // find new tail: (n - k - 1)th node from start
        int stepsToNewTail = n - k;
        ListNode* newTail = head;
        for(int i = 1; i < stepsToNewTail; i++){
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};