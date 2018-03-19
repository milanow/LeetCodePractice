/* 413. Arithmetic Slices
 * A stright forward solution. Finding out those arithmetic slices as long as
 * possible inside the array. Calculate the sub-arithmetic slices by
 * calArithBlock. 
 */

class Solution {
    int calArithBlock(int len){
        if(len < 3) return 0;
        return (len-1)*(len-2)/2;
    }
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if(len < 3) return 0;
        
        int res = 0;
        int start = 0, diff = A[1] - A[0];
        for(int i = 2; i < len; i++){
            if(A[i] - A[i-1] == diff) continue;
            else{
                res += calArithBlock(i - start);
                start = i-1;
                diff = A[i] - A[i-1];
            }
        }
        res += calArithBlock(len - start);
        return res;
    }
};