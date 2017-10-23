/* 635. Design Log Storage System
 * using hashmap to store the timestamp->ids, another const map to store the gran level
 * each time of retrieving, we search through the map and find all qualified timestamp
 */

public class LogSystem {
    
    Dictionary<string, int> map;
    static Dictionary<string, int> mapping = new Dictionary<string, int>{
        {"Year", 0}, {"Month", 1}, {"Day", 2}, {"Hour", 3},
        {"Minute", 4}, {"Second", 5}
    };

    public LogSystem() {
        map = new Dictionary<string, int>();
    }
    
    public void Put(int id, string timestamp) {
        map.Add(timestamp, id);
    }
    
    public IList<int> Retrieve(string s, string e, string gra) {
        int[] start = NumeralTime(s, 6);
        int[] end = NumeralTime(e, 6);
        int n = mapping[gra];
        var res = new List<int>();
        
        foreach(var p in map){
            int[] cur = NumeralTime(p.Key, n+1);
            if(Larger(cur, start, n) && Smaller(cur, end, n)) res.Add(p.Value);
        }
        return res;
    }
    
    private bool Larger(int[] tar, int[] start, int level){
        for(int i = 0; i <= level; ++i){
            if(tar[i] < start[i]) return false;
            else if(tar[i] > start[i]) return true;
        }
        return true;
    }
    
    private bool Smaller(int[] tar, int[] end, int level){
        for(int i = 0; i <= level; ++i){
            if(tar[i] < end[i]) return true;
            else if(tar[i] > end[i]) return false;
        }
        return true;
    }
    
    private int[] NumeralTime(string timestamp, int len){
        string[] times = timestamp.Split(':');
        int[] res = new int[len];
        for(int i = 0; i < len; ++i){
            res[i] = Int32.Parse(times[i]);
        }
        res[0] -= 2000;
        return res;
    }
}

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.Put(id,timestamp);
 * IList<int> param_2 = obj.Retrieve(s,e,gra);
 */