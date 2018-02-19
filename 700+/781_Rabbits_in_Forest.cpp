/* 781. Rabbits in Forest
 * Some rabbits answered the question, some not. But when same rabbits 
 * answered the question, their answers must be same.
 * Therefore, we use a hashmap to record the frequency of answers
 * However, there might be multiple colors rabbits may have same number
 * of rabbits. In this condition, we assume "as less colors as possible" and
 * find out how many colors it requires to reach the frequency.
 */

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(int i: answers){
            mp[i]++;
        }
        
        int res = 0;
        for(auto& p: mp){
            if(p.first >= p.second - 1){
                res += p.first + 1;
            }else{
                // find out how many colors can reach the frequency
                while(p.first < p.second - 1){
                    res += (p.first + 1);
                    p.second -= (p.first + 1);
                }
                res += (p.first + 1);
            }
        }
        return res;
    }
};