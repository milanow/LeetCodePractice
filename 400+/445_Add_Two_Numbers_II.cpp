/* 445. Add Two Numbers II
 * Adding numbers inside listnode is annoying because it can only reach next
 * node, which means going to lower digit when doing calculation. However, carry needs
 * to be considered when calculating higher digit. That seems a inversed process.
 * So the solution firstly reverse the number and making carries working fine with adding
 * oeration in listnode.
 * Then reverse it back as final answer
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* addToFront(int value, ListNode* node){
        ListNode* newnode = new ListNode(value);
        newnode->next = node;
        return newnode;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        ListNode* head1 = l1, *head2 = l2, *res = nullptr;
        while(head1){
            head1 = head1->next;
            len1++;
        }
        while(head2){
            head2 = head2->next;
            len2++;
        }
        
        // making the reversed answer without considering carry
        head1 = l1, head2 = l2;
        while(len1 > 0 && len2 > 0){
            int sum = 0;
            if(len1 >= len2){
                sum += head1->val;
                head1 = head1->next;
                len1--;
            }
            if(len2 > len1){
                sum += head2->val;
                head2 = head2->next;
                len2--;
            }
            res = addToFront(sum, res);
        }
        
        head1 = head2 = res;
        res = nullptr;
        
        // handling carries
        int carry = 0;
        while(head1){
            head1->val += carry;
            carry = head1->val / 10;
            head1->val %= 10;
            head1 = head1->next;
        }
        
        // reverse the list
        while(head2){
            auto tmp = head2->next;
            head2->next = res;
            res = head2;
            head2 = tmp;
        }
        if(carry) res = addToFront(1, res);
        return res;
    }
};