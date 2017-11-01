/* 556. Next Greater Element III
 * Typical next_permutaion
 * Convert to string for easier manipulation.
 * First, find from lowest digit, find the first index where num[index] < num[index+1]
 * Secondly, reverse the order of digits lower than the index digit (on the right of index)
 * Thirdly, find the first element in previous reversed sub-number that greater than
 * indexed digit and swap them.
 * Convert the string to long to avoid overflow
 */


class Solution {
public:
    int nextGreaterElement(int n) {
        string nstr = to_string(n);
        
        int index = nstr.length() - 2;
        for(; index >= 0 && nstr[index] >= nstr[index+1]; index--){}
        if(index == -1) return -1;
        
        reverse(nstr.begin() + index + 1, nstr.end());
        for(int j = index + 1; j < nstr.length(); j++){
            if(nstr[j] > nstr[index]){
                swap(nstr[j], nstr[index]);
                break;
            }
        }
        long next = stol(nstr);
        return next > INT_MAX? -1: next;
    }
};