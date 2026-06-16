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
    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == NULL) return NULL;
        ListNode *mid = head, *track = head, *prev = head;
        while(track != NULL && track -> next != NULL){
            prev = mid;
            mid = mid -> next;
            track = (track -> next) -> next;
        }
        prev -> next = (prev -> next) -> next;
        return head;
    }
};