/* 779. K-th Symbol in Grammar
 * When encountering such "generation" problem, it can always be solved by recursion.
 * Treating this structure as a tree, then a left/right child's value is determined by
 * its parent.
 */

class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1) return 0;
        
        if(K % 2 == 0) return (kthGrammar(N - 1, K / 2) == 0)?1: 0;
        else return (kthGrammar(N - 1, (K + 1)/2) == 0)? 0: 1;
    }
};