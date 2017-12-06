/* 488. Zuma Game
 * The idea is easy, but the process is complicated
 * To sum up, the solution follows the idea of backtracking
 * for every ball in hand, we check if this ball can help eliminate balls
 * in board, if does, we 'shoot out' the ball and eliminating the balls in board
 * shrink the board and dive into next recursion. 
 * Checking each position at baord for every ball in hand and see which one has 
 * the min steps
 */

class Solution {
    #define MAX_STEP 6
public:
    int findMinStep(string board, string hand) {
        sort(begin(hand), end(hand));
        int res = helper(board, hand);
        return res > hand.size()? -1: res;
    }
    
    // each healper function only take one step
    // it is much like a backtracking process
    int helper(string b, string h){
        if(b.length() == 0) return 0;
        if(h.length() == 0) return MAX_STEP;
        int res = MAX_STEP;
        for(int i = 0; i < h.length(); i++){
            // start finding possible position in b
            // where h[i] can insert can eliminate some balls
            int j = 0;
            int blen = b.length();
            while(j < blen){
                int k = b.find(h[i], j);
                // cannot find a character in hand, but it doesn't mean we cannot finish the game,
                // since we don't need to use up balls in hand;
                if(k == string::npos) break;
                
                // find out a 2 consecutive h[i] in board
                if(k < blen - 1 && b[k] == b[k+1]){
                    string nextb = shrinkStr(b.substr(0, k) + b.substr(k+2));
                    // this is the best result, we don't need to find other result because the problem only needs min step
                    if(nextb.length() == 0) return 1;
                    string nexth = h;
                    // erase only 1 h[i]
                    nexth.erase(i, 1);
                    res = min(res, helper(nextb, nexth) + 1);
                    // b[k] == b[k+1] thus we don't need to find from k+1
                    // later j will be assigned as k+1, thus next finding positon j is: k+2;
                    k++;
                }
                
                // even if there is no 2-consecutive h[i] in board, but we have 2 h[i] in hand
                // we can take two steps to eliminate h[i] in b, which is b[k];
                // note: h is sorted, such that same ball is neighboured
                // note2: making it 'else if' since we only need insert one extra ball if there are 2 already in board
                else if(i > 0 && h[i] == h[i-1]){
                    string nextb = shrinkStr(b.substr(0, k) + b.substr(k+1));
                    if(nextb.length() == 0) return 2;
                    string nexth = h;
                    nexth.erase(i, 1);
                    nexth.erase(i-1, 1);
                    res = min(res, helper(nextb, nexth) + 2);
                    
                    // no need to selfincrese k here
                }
                
                // skip character h[i] we have checked in board
                j = k + 1;
            }
        }
        return res;
    }

    string shrinkStr(string s){
        while(s.size() > 0){
            int start = 0;
            bool done = true;
            for(int i = 0; i <= s.size(); i++){
                if(i == s.size() || s[start] != s[i]){
                    // meeting with 3 consecutive character
                    if(i - start >= 3){
                        done = false;
                        s = s.substr(0, start) + s.substr(i);
                        
                        // start from index 0 again because erasing may have affected previous balls
                        break;
                    }
                    start = i;
                }
            }
            if(done) break;
        }
        return s;
    }
};