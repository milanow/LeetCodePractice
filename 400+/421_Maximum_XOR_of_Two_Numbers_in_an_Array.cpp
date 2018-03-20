/* 421. Maximum XOR of Two Numbers in an Array
 * Checking from the highest bits to see if there is any two of prefix-numbers
 * could form "tmp". Since if A^B = C, then A^C=B, B^C=A, we only need check "cand ^ tmp"
 * Then why maxXOR is one of the "tmp" in the code? Because if two prefix-numbers can form
 * a tmp in previous iteration, When we check the new masks, they can still form the new "tmp"
 * or they cannot then the answer is previous "tmp".
 */

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mx = 0, mask = 0;
        for(int i = 30; i >=  0; i--){
            mask |= (1 << i);
            unordered_set<int> st;
            for(int n: nums){
                st.insert(mask & n);
            }
            
            int tmp = mx | (1 << i);
            for(int cand: st){
                if(st.find(cand ^ tmp) != st.end()){
                    mx = tmp;
                    break;
                }
            }
        }
        return mx;
    }
};