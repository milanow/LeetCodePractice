/* 401. Binary Watch
 * Iterating all possible time. Check to see if any time that have same '1' with num
 */

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int h = 0; h < 12; h++){
            for(int m = 0; m < 60; m++){
                if(bitset<32>(h << 6 | m).count() == num){
                    res.emplace_back(to_string(h) + (m < 10? ":0": ":") + to_string(m));
                }
            }
        }
        return res;
    }
};