/* 631. Design Excel Sum Formula
 * The key to maintain such structure is to keep track on the relations among cells
 * When set(cellA) is called, we need to update all the cells that cellA contributes,
 * and disconnected with cells who contribute to cellA
 * When sum(cellA) is called, we need to disconnected with cells who contribute to cellA first
 * Then update/save the relations of which cells contribute to cellA,
 * Then update all cells that cellA contribute
 */

class Excel {
    // fward links a cell to all the cells which use it for sum, and it may be used for multiple times due to overlap ranges
    unordered_map<int, unordered_map<int, int>> fward;
    // bward links a cell to all the cells that contribute to its sum, when reset it, bward is used to eliminate keys and update
    // fward;
    unordered_map<int, unordered_set<int>> bward;
    vector<vector<int>> content;
public:
    Excel(int H, char W) {
        content = vector<vector<int>>(H+1, vector<int>(W-'A'+1, 0));
        fward.clear();
        bward.clear();
    }
    
    void set(int r, char c, int v) {
        int col = c-'A', key = r*26+col;
        // update cells via fward;
        update(r, col, v);
        // update fward via bward;
        if(bward.find(key) != bward.end()){
            for(auto k: bward[key]){
                fward[k].erase(key);
            }
            bward.erase(key);
        }
    }
    
    // updating cell via BFS
    void update(int row, int col, int val){
        int prev = content[row][col];
        content[row][col] = val;
        
        queue<int> keyq, increq;
        keyq.push(row*26+col);
        increq.push(val - prev);
        while(!keyq.empty()){
            int key = keyq.front(), diff = increq.front();
            keyq.pop();
            increq.pop();
            if(fward.find(key) != fward.end()){
                for(auto i = fward[key].begin(); i != fward[key].end(); ++i){
                    int k = i->first; 
                    // push new key into queue
                    keyq.push(k);
                    increq.push(diff*(i->second));
                    // update the cell
                    content[k/26][k%26] += diff*(i->second);
                }
            }
        }
    }
    
    int get(int r, char c) {
        return content[r][c-'A'];
    }
    
    int sum(int r, char c, vector<string> strs) {        
        int col = c-'A', key = r*26 + col, ans = 0;
        
        if(bward.find(key) != bward.end()){
            for(auto k: bward[key]){
                fward[k].erase(key);
            }
            bward.erase(key);
        }
        
        // update cell value
        for(string str: strs){
            int p = str.find(':');
            int top, bot, left, right;
            left = str[0] - 'A';
            right = str[p+1] - 'A';
            if(p == -1){
                top = stoi(str.substr(1));
            }else{
                top = stoi(str.substr(1, p-1));
            }
            bot = stoi(str.substr(p+2));
            for(int i = left; i <= right; ++i){
                for(int j = top; j <= bot; ++j){
                    ans += content[j][i];
                    fward[j*26+i][key]++;
                    bward[key].insert(j*26+i);
                }
            }
        }

        update(r, col, ans);
        return ans;
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */