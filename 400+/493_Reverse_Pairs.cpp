/* 493. Reverse Pairs
 * Divide and Conquer solution, we count the pairs along as sorting the array 
 * Each process we divide the array into two part, 
 * We count how many left elements is larger than 2 * right elements
 * which is *i > 2L * *j, making it 'long' incase out of int32's range.
 * For those pairs resides in left or right part of array,
 * We pass it down to next recursion and adding up the result together
 */

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return sortAndCount(begin(nums), end(nums));
    }
    
private:
    int sortAndCount(vector<int>::iterator start, vector<int>::iterator stop){
        if(stop - start <= 1) return 0;
        auto mid = start + (stop - start) / 2;
        int cnt = sortAndCount(start, mid) + sortAndCount(mid, stop);
        for(auto i = start, j = mid; i != mid; i++){
            // no need to start counting j from mid every time, because previous i
            // must smaller than current i, if previous i can make j "reaching" j
            // then current i can either be part of important pair 
            while(j != stop && *i > static_cast<long>(2) * (*j)) j++;
            cnt += j - mid;
        }
        inplace_merge(start, mid, stop);
        return cnt;
    }    
};