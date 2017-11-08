/* 526. Beautiful Arrangement
 * A backtracking problem, continues to pass down valid arrangement and counting
 * the number of possible answer
 */

class Solution {
public:
    int countArrangement(int N) {
        vector<int> ivec(N, 0);
        iota(begin(ivec), end(ivec), 1);
        return count(N, ivec);
    }
    
    int count(int n, vector<int>& v){
        if(n <= 1) return 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(v[i]%n == 0 || n%v[i] == 0){
                swap(v[i], v[n-1]);
                ans += count(n-1, v);
                swap(v[i], v[n-1]);
            }
        }
        return ans;
    }
};