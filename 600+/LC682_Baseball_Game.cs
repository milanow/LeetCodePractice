/* LC682 - Baseball Game
 * The idea is straightforward, use stack to record previous results, when encounters '+',
 * checking if there were enough number in stack. In every iteration, push the points into 
 * stack
 */

public class Solution {
    public int CalPoints(string[] ops) {
        Stack<int> stk = new Stack<int>();
        int sum = 0;
        
        for(int i = 0; i < ops.Length; ++i){
            if(ops[i] == "+"){
                if(stk.Count == 0) continue;
                if(stk.Count == 1){
                    int topVal = stk.Peek();
                    stk.Push(topVal);
                    sum += topVal;
                    continue;
                } 
                int tmp = stk.Pop();
                int val = tmp + stk.Peek();
                stk.Push(tmp);
                stk.Push(val);
                sum += val;
            }else if(ops[i] == "D"){
                if(stk.Count == 0) continue;
                sum += stk.Peek()*2;
                stk.Push(stk.Peek()*2);
            }else if(ops[i] == "C"){
                if(stk.Count == 0) continue;
                sum -= stk.Pop();
            }else{
                stk.Push(Int32.Parse(ops[i]));
                sum += stk.Peek();
            }
        }
        return sum;
    }
}