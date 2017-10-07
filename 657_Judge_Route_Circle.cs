/* 657. Judge Route Circle
 * return true only if 'L' count equals 'R' count && 'U' count equals 'D' count
 */

public class Solution {
    public bool JudgeCircle(string moves) {
        int len = moves.Length;
        if(len == 0) return true;
        
        int ver = 0, hor = 0;
        for(int i = 0; i < len; ++i){
            if(moves[i] == 'U') ver += 1;
            else if(moves[i] == 'D') ver -= 1;
            else if(moves[i] == 'L') hor -= 1;
            else if(moves[i] == 'R') hor += 1;
        }
        return ver == 0 && hor == 0;
    }
}