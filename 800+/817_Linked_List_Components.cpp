/* 817. Linked List Components
 * if there was a continuous group, then it must have an 'end', where G has the value but G does't have next
 * node's value
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
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> st (G.begin(), G.end());
        int res = 0;
        while (head != NULL) {
            if (st.find(head->val) != st.end() && (head->next == NULL || st.find(head->next->val) == st.end())) res++;
            head = head->next;
        }
        return res;
    }
};