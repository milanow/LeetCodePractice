/* 725. Split Linked List in Parts
 * No tricks for this problem. First calculate the length and find out how many nodes
 * a part need. Then fill the result array as needed
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        ListNode* head = root;
        while(head){
            len++;
            head = head->next;
        }
        
        int tar = len / k + ((len%k)? 1: 0); // 3
        int longer = len%k; // 1
        vector<ListNode*> res;
        while(root){
            ListNode* node = root;
            int cnt = 1;
            while(cnt != (longer > 0? tar: len%k? tar-1: tar)){
                cnt++;
                root = root->next;
            }
            ListNode* tmp = root->next;
            root->next = nullptr;
            root = tmp;
            res.push_back(node);
            longer--;
        }
        
        while(res.size() < k){
            res.push_back(nullptr);
        }
        return res;
    }
};