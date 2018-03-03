/* 711. Number of Distinct Islands II
 * Finding islands is easy, we just need to dfs all adjcent '1' cell
 * However, the key of the problem is, how to save the islands' shapes.
 * The solution is to save all coord-differences with left-top corner
 * But we can rotate/reflect an island to gain a new set of coord-differences
 * because after rotation/reflection the left-top corner alters
 * 
 * To solve this issue, the solution "normalize" the island by setting all 8
 * possible islands(4 rotations * 2 reflection = 8 possible islands)'s left-top
 * corner to [0, 0] and sort these 8 sets of corrdnates. Saving the top sort order
 * of coord-set into our island map.
 * Two islands with same shape but different coord-sets should be the same after normalization
 * 
 * We iteratively find island and normalize the island and save the island after normalization
 * in a set without repeat islands. After all search the set's size is what we want,
 * representing the number of distint islands
 */ 

class Solution {
    unordered_map<int, vector<pair<int, int>>> mp;
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        if(!n) return 0;
        int idx = 1;
        set<vector<pair<int, int>>> st;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    vector<pair<int, int>> newIsland;
                    dfs(newIsland, grid, i, j, ++idx);
                    st.insert(norm(mp[idx]));
                }
            }
        }
        return st.size();
    
    }

private:
    void dfs(vector<pair<int, int>>& island, vector<vector<int>>& grid, int x, int y, int index){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1) return;
        grid[x][y] = index;
        mp[index].push_back({x, y});
        dfs(island, grid, x+1, y, index);
        dfs(island, grid, x-1, y, index);
        dfs(island, grid, x, y+1, index);
        dfs(island, grid, x, y-1, index);
    }
    
    vector<pair<int, int>> norm(vector<pair<int, int>>& island){
        vector<vector<pair<int, int>>> s(8);
        for(auto& p: island){
            int a = p.first, b = p.second;
            s[0].push_back({a, b});
            s[1].push_back({a, -b});
            s[2].push_back({-a, b});
            s[3].push_back({-a, -b});
            s[4].push_back({b, a});
            s[5].push_back({-b, a});
            s[6].push_back({b, -a});
            s[7].push_back({-b, -a});
        }
        // sort the possible islands from lowest [r, c] to highest [r, c]
        for(auto& il: s) sort(il.begin(), il.end());
        // move the islands to [0, 0]
        for(auto& il: s){
            for(int i = 1; i < il.size(); i++){
                il[i] = {il[i].first - il[0].first, il[i].second - il[0].second};
            }
            il[0] = {0, 0};
        }
        // it doesn't matter how stl sorting the islands, because if two islands have the same shape, same
        // vector<pair<int, int>> would be the first element in s
        sort(s.begin(), s.end());
        return s[0];
    }
};