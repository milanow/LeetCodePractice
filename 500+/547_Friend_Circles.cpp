/* 547. Friend Circles
 * A typical union-find problem,
 * note: k = parent[k] = parent[parent[k]] is to trim the tree to make it flat
 */


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        if(N == 0) return 0;
        
        vector<int> parent(N, 0);
        iota(parent.begin(), parent.end(), 0);
        
        int group = N;
        
        for(int i = 0; i < N; ++i){
            for(int j = i+1; j < N; ++j){
                if(M[i][j] == 1){
                    int rootA = root(parent, i);
                    int rootB = root(parent, j);
                    if(rootA != rootB){
                        parent[rootA] = rootB;
                        group--;
                    }
                }
                
            }
        }
        return group;
    }
    
    int root(vector<int>& parent, int k){
        while(k != parent[k]){
            k = parent[k] = parent[parent[k]];
        }
        return k;
    }
};