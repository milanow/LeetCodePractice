/* 546. Remove Boxes
 * A 'dp' solution
 * mem[l][r][k] represents points of subArray of boxes (index of l to r)
 * k is defined as how many same characters appending behind boxes[r] equals boxes[r]
 * eg: 132222 where 1 is at index 0, such that l = 0,
 *      r here is 2 instead of 5
 *      k is 3, which represents 3 '2's appending behind
 *
 * Then consider the strategy, the only thing we don't know about a set of l, r, k is:
 * in such situation: 21344553, should we remove 2 '3' together or not
 * So we iterater from l, to see if any character is same with the boxes[r],
 * in current case when index = 2, we found boxes[2] = boxes[r] = 3
 * The thing we need to consider is remove them together or not.
 */

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int mem[100][100][100] = {0};
        return dfs(boxes, mem, 0, n-1, 0);
    }
    
    int dfs(vector<int>& boxes, int mem[100][100][100], int l, int r, int k){
        if(l > r) return 0;
        if(mem[l][r][k] != 0) return mem[l][r][k];
        
        // shrink the array
        while(l < r && boxes[r-1] == boxes[r]) { r--; k++; }
        mem[l][r][k] = dfs(boxes, mem, l, r-1, 0) + (k+1)*(k+1);
        for(int i = l; i < r; i++){
            if(boxes[i] == boxes[r]){
                mem[l][r][k] = max(mem[l][r][k], dfs(boxes, mem, l, i, k+1) + dfs(boxes, mem, i+1, r-1, 0));
            }
        }
        return mem[l][r][k];
    }
};