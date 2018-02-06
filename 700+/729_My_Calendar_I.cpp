/* 729. My Calendar I
 * a vector<pair<int, int>> to save booked time, for each book, iteratively checking each
 * booked time to see any conflict.
 * Note: map<int, int> can also help, but for this problem, it seems vector is faster
 */

class MyCalendar {
    // the first int is start of a booked schedule, second int is the end
    vector<pair<int, int>> dict;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(dict.size() == 0){
            dict.emplace_back(start, end);
            return true;
        }
        
        for(auto& p: dict){
            // if(p.first >= end) break;
            if(max(p.first, start) < min(p.second, end)) return false;
        }
        dict.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */