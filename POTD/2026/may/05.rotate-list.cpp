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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0 || head -> next == NULL) return head;
        ListNode *temp = head, *first = head;
        int cnt = 0;
        while(temp != NULL) {
            cnt++;
            temp = temp -> next;
        }
        temp = head;
        k = k % cnt;
        if(k == 0) return head;
        k = cnt - k;
        while(k != 1) {
            temp = temp -> next;
            k--;
        }
        ListNode* temp1 = temp -> next;
        head = temp -> next;
        temp -> next = NULL;
        while(temp1 -> next != NULL) {
            temp1 = temp1 -> next;
        }
        temp1 -> next = first;
        return head;
    }
};