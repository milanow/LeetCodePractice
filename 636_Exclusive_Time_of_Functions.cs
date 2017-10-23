/* 636. Exclusive Time of Functions
 * After obervation, we found that function execution time is calculated by adding each "time segement"
 * together when the function is active. "Time segement" is the timeline cut by "start" or "end".
 * We use a stack to record current active function, when there is a time segement available, we add the 
 * time to that function. If the time segement is cut by "start->end", then add "end-start+1",
 * if the time segement is cut by "end->start", then add "start-end-1", otherwise, add "segEnd-segStart"
 */

public class Solution {
    public int[] ExclusiveTime(int n, IList<string> logs) {
        int[] res = new int[n];
        var stkThread = new Stack<int>();
        
        bool lastStart = false;
        int lastEntry = -1;
        for(int i = 0; i < logs.Count; ++i){
            int len = logs[i].Length;
            int idx = len-1;
            while(logs[i][idx] >= '0' && logs[i][idx] <= '9') --idx;
            int curTime = Int32.Parse(logs[i].Substring(idx+1, len-idx-1));
            idx = 0;
            while(logs[i][idx] >= '0' && logs[i][idx] <= '9') ++idx;
            int curFunc = Int32.Parse(logs[i].Substring(0, idx));
            
            if(logs[i][idx+1] == 's'){
                if(stkThread.Count != 0){
                    if(lastStart){
                        res[stkThread.Peek()] += curTime - lastEntry;
                    }else{
                        res[stkThread.Peek()] += curTime - lastEntry - 1;
                    }
                }
                
                stkThread.Push(curFunc);
                lastStart = true;
            }else{
                if(lastStart){
                    res[stkThread.Peek()] += curTime - lastEntry + 1;
                }else{
                    res[stkThread.Peek()] += curTime - lastEntry;
                }
                
                stkThread.Pop();
                lastStart = false;
            }
            lastEntry = curTime;
        }
        return res;
        
    }
}