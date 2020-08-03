/*
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = (l1->val + l2->val) / 10;
        ListNode* ptr = new ListNode((l1->val + l2->val) % 10);
        ListNode* head = ptr; // starting node (to be returned at the end)
        
        l1 = l1->next; l2 = l2->next;
        while(l1 && l2) {
            ptr->next = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            ptr = ptr->next;
            l1 = l1->next; l2 = l2->next;
        }
        while(l1) {
            ptr->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            ptr = ptr->next;
            l1 = l1->next;
        }
        while(l2) {
            ptr->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            ptr = ptr->next;
            l2 = l2->next;
        }
        // even after the end of two lists if carry still present then add one node with value one.
        if(carry) 
            ptr->next = new ListNode(1);
        
        return head;
    }
};