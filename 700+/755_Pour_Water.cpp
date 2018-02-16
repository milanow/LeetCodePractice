
/* 755. Pour Water
 * This problem could be seen as a recursion problem, every droplet represents
 * a recursion process. In each recursion, check left & right to see where the
 * droplet should go. And continue pass down to next recursion by (V-1). When V=0,
 * It means the water slot has been reaching to a "stable" stage
 */

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        if(V == 0) return heights;
        // the algorithm is to recursively handle one droplet a time
        int leftlolvl = heights[K], leftindex = -1;
        int rightlolvl = heights[K], rightindex = heights.size();
        // check to left
        for(int i = K-1; i >= 0; i--){
            if(heights[i] > leftlolvl) break;
            if(leftlolvl > heights[i]){
                leftlolvl = heights[i];
                leftindex = i;
            }
        }
        // check to right
        for(int i = K+1; i < heights.size(); i++){
            if(heights[i] > rightlolvl) break;
            if(rightlolvl > heights[i]){
                rightlolvl = heights[i];
                rightindex = i;
            }
        }
        // remain at index K
        if(heights[K] == min(leftlolvl, rightlolvl)){
            heights[K]++;
        }
        // left has priority, so moving direction is not determined by leftlolvl & rightlolvl
        else if(leftlolvl < heights[K]){
            heights[leftindex]++;
        }
        else if(rightlolvl < heights[K]){
            heights[rightindex]++;
        }
        return pourWater(heights, V-1, K);
    }
};