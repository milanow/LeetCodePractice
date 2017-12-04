/* 492. Construct the Rectangle
 * Finding out the nearest pair of factor to the "middle" (sqrt(area))
 */

class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int i = sqrt(area); i > 0; i--){
            if(!(area%i)) return {area/i, i};
        }
    }
};