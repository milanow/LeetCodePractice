/* Split Array With Same Average
 * This solution comes from Leetcode forum,
 * 1. if there exist a subarray that make the split arrays same average, then sumOfSubarray / lenOfSubarray = totalSum / len
 *    it means there exist an i, where 0 < i <= len/2, totalsum*i % n == 0, which means sumOfSubarray is an integer
 * 2. sums[i] represents possible sums of subarray with i length, we only need to check at most length of m = len/2 because
 *    there must be a subarray that its length is smaller or equal than m
 */

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
       int n = A.size(), m = n/2, totalSum = accumulate(A.begin(), A.end(), 0);
        // 1. early pruning
        bool isPossible = false;
        for (int i = 1; i <= m && !isPossible; ++i) 
            if (totalSum*i%n == 0) isPossible = true;
        if (!isPossible) return false;
        // 2. DP like knapsack
        vector<unordered_set<int>> sums(m+1);
        sums[0].insert(0);
        for (int num: A) {
            for (int i = m; i >= 1; --i) 
                for (const int t: sums[i-1]) 
                    sums[i].insert(t + num);
        }
        for (int i = 1; i <= m; ++i) 
            if (totalSum*i%n == 0 && sums[i].find(totalSum*i/n) != sums[i].end()) return true;
        return false;
    }
};