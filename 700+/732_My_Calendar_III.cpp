/* 732. My Calendar III
 * Thinking this problem as a "scan line" problem
 * Which means scanning timeline (timestamp) from the beginning and update the
 * max booked time
 */

class MyCalendarThree {
    map<int, int> mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int total = 0, res = 0;
        for(auto& p: mp){
            res = max(res, total += p.second);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */