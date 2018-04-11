/* 803. Bricks Falling When Hit
 * This is a typical union-find solution. Except that we need to record the size
 * of each groups/islands. First, we eliminate each bricks that need to be erase to
 * have a new grid. And union cells in the new grid. And then secondly, we put those
 * bricks back to the new grid, and do the new union opeartions if possible. If we 
 * we found that after new union operation, the group size of roof increases, then it
 * represents some bricks have been falled because we erase current brick.
 * Note the "putting back brick" operation has to be inversed (from back side)
 * Because if not, we may miss some bricks because of latter erase operation.
 */

struct Node{
    int rank, parent;
    Node():rank(1),parent(-1){};
};

class UnionFind{
public:
    UnionFind(int n){
        uf = vector<Node>(n);
    }
    int Find(int x){
        if(uf[x].parent < 0){
            return x;
        }
        int res = Find(uf[x].parent);
        uf[x].parent = res;
        return res;
    }
    int GetRank(int x){
        int parX = Find(x);
        return uf[parX].rank;
    }

    void Union(int x, int y){
        int parX = Find(x);
        int parY = Find(y);
        if(parX == parY){
            return;
        }

        if(uf[parX].rank > uf[parY].rank){
            uf[parY].parent = parX;
            uf[parX].rank += uf[parY].rank;
        }
        else{
            uf[parX].parent = parY;
            uf[parY].rank += uf[parX].rank;

        }
    }

    vector<Node> uf;
private:
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>> grid, vector<vector<int>> hits) {
        int m = grid.size();
        if(!m) return vector<int>();
        int n = grid[0].size();
        if(!n) return vector<int>();
        vector<vector<int>> mat = grid;
        
        int hitsz = hits.size();
        vector<int> res(hitsz, 0);
        // erase all target bricks
        for(auto& hit: hits){
            mat[hit[0]][hit[1]] = 0;
        }
        
        UnionFind uf(m*n+1);
        // node m*n is the roof
        for(int i = 0; i < n; i++){
            if(mat[0][i] == 1) uf.Union(i, m*n);
        }
        
        // union original nodes
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    if(mat[i-1][j] == 1){
                        uf.Union(i*n + j, (i-1)*n + j);
                    }
                    if(j > 0 && mat[i][j-1] == 1){
                        uf.Union(i*n + j, i*n + j - 1);
                    }
                }
            }
        }

        for(int h = hitsz - 1; h >= 0; h--){
            int x = hits[h][0];
            int y = hits[h][1];
            
            if(grid[x][y] == 1){
                int preRoofGroupsz = uf.GetRank(m*n);
                mat[x][y] = 1;
                if(x < m-1 && mat[x+1][y] == 1) uf.Union(x*n + y, (x+1)*n + y);
                if(x > 0 && mat[x-1][y] == 1) uf.Union(x*n + y, (x-1)*n + y);
                if(y < n-1 && mat[x][y+1] == 1) uf.Union(x*n + y, x*n + y + 1);
                if(y > 0 && mat[x][y-1] == 1) uf.Union(x*n + y, x*n + y - 1);
                if(x == 0) uf.Union(x*n + y, m*n);
                int curRoofGroupsz = uf.GetRank(m*n);
                
                int parent1 = uf.Find(x*n + y);
                int parent2 = uf.Find(m*n);
                if(parent1 == parent2){
                    res[h] = curRoofGroupsz - preRoofGroupsz - 1;
                }
            }
        }
        return res;
    }
};