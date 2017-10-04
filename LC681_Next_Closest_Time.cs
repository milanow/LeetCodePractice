/* LC681 Next Cloesest Time
 * Firstly, find out all the time candidates
 * Secondly, check if candidates are valid and not original time
 * Last, calculate the time distance and find out the smallest time distance
 */

public class Solution {
    string nextTime = "";
    int minDiff = 24*60;
    
    public string NextClosestTime(string time) {
        HashSet<char> st = new HashSet<char>();
        st.Add(time[0]);
        st.Add(time[1]);
        st.Add(time[3]);
        st.Add(time[4]);
        var cands = new List<string>();
        foreach(char c in st){
            cands.Add(c.ToString());
        }
        
        for(int i = 0; i < 3; ++i){
            var tmp = new List<string>();
            for(int j = 0; j < cands.Count; ++j){
                foreach(char c in st){
                    tmp.Add(cands[j] + c.ToString() + (i == 0? ":": ""));
                }
            }
            cands = tmp;
        }
        
        for(int i = 0; i < cands.Count; ++i){
            if(ValidTime(cands[i]) && cands[i] != time){
                int diff = TimeDiff(time, cands[i]);
                if(minDiff > diff){
                    nextTime = cands[i];
                    minDiff = diff;
                }
            }
        }
        return nextTime == ""? time: nextTime;
    }
    
    private bool ValidTime(string time){
        int h1 = time[0] - '0', h2 = time[1] - '0';
        int m1 = time[3] - '0';
        
        if(h1 > 2 || h1 == 2 && h2 > 3 || m1 > 5) return false;
        return true;
    }
    
    private int TimeDiff(string time1, string time2){
        int val1 = ((time1[0]-'0')*10 + time1[1]-'0')*60 + (time1[3]-'0')*10 + (time1[4]-'0');
        int val2 = ((time2[0]-'0')*10 + time2[1]-'0')*60 + (time2[3]-'0')*10 + (time2[4]-'0');
        
        if(val2 < val1) val2 += 24*60;
        return val2 - val1;
    }
}