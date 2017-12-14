/* 481. Magical String
 * Follow the instructions to dynamically build the magic string
 * A slow pointer indicate how many 1 or 2 to be inserted
 */

public class Solution {
    public int MagicalString(int n) {
        StringBuilder sb = new StringBuilder("122");
        int i = 2;
        while(sb.Length < n){
            sb.Append(sb[sb.Length-1] == '1'? '2': '1', sb[i++] - '0');
        }
        
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(sb[j] == '1') sum++;
        }
        return sum;
    }
}