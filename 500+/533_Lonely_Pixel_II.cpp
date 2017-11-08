/* 533. Lonely Pixel II
 * 1. Collect how many 'B's per row and col, counting the number of same row by hashmap
 * 2. rule1 says both rows[i] & cols[j] equals N, also picture[i][j] == N
 *    rule2 says mp[srows[i]] = N
 */

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int m = picture.size();
        if(!m) return 0;
        int n = picture[0].size();
        if(!n) return 0;
        
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        vector<string> srows(m);
        unordered_map<string, int> mp;
        
        for(int i = 0; i < m; i++){
            string s("");
            for(int j = 0; j < n; j++){
                if(picture[i][j] == 'B'){
                    rows[i]++;
                    cols[j]++;
                }
                s.push_back(picture[i][j]);
            }
            mp[s]++;
            srows[i] = s;
        }
        
        int res = 0;
        for(int i = 0; i < m; i++){
            if(rows[i] == N && mp[srows[i]] == N){
                for(int j = 0; j < n; j++){
                    if(cols[j] == N && picture[i][j] == 'B') res++;
                }
            }
        }
        return res;
    }
};