/* 646. Maximum Length of Pair Chain
 * Note, C# cannot Sort int[] in 2D array int[,], it can only Sort in[] in jagged array in[][]
 * So I implement the solution via C++, (I tried to write an IComparer<T> not IComparer)
 * 
 * The core idea is to rearrange the input array by comparing the end of pair, because we
 * try to pick up pair where ends the earliest as we iterate the array.
 */

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto comp = [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        };
        sort(pairs.begin(), pairs.end(), comp);
        int cnt = 0;
        for(int i = 0, j = 0; j < pairs.size(); ++j){
            if(j == 0 || pairs[i][1] < pairs[j][0]){
                cnt++;
                i = j;
            }
        }
        return cnt;
    }
};