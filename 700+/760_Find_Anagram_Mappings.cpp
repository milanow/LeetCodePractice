/* 760. Find Anagram Mappings
 * Save value->index pair in B as an unordered_map
 * iterating through A and check the corresponding value in B
 */

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, stack<int>> dict;
        for(int i = 0; i < B.size(); i++){
            dict[B[i]].push(i);
        }
        
        vector<int> res;
        for(int i = 0; i < A.size(); i++){
            if(dict[A[i]].size() == 0) return vector<int>();
            res.push_back(dict[A[i]].top());
            dict[A[i]].pop();
        }
        return res;
    }
};