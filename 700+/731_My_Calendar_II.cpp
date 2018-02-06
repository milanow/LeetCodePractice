/* 731. My Calendar II
 * Save My Calendar I as a "backup". If encounter an overlap at current calendarTwo, 
 * then book it inside calendarOne. If found an overlap at calendarOne, then this time
 * cannot be booked due two it has some time where are booked twice
 */


class MyCalendar {
    vector<pair<int, int>> dict;
public:
    MyCalendar(){
        
    }
    
    bool book(int start, int end){
        for(auto& p: dict){
            if(max(p.first, start) < min(p.second, end)) return false;
        }
        dict.emplace_back(start, end);
        return true;
    }
};

class MyCalendarTwo {
    vector<pair<int, int>> dict;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        MyCalendar mycal;
        for(auto& p: dict){
            if(max(p.first, start) < min(p.second, end)){
                pair<int, int> overlap = getOverLapped(p, start, end);
                // if overlapped overlap happened, then return false
                // The allowed overlaps are saved into mycal
                if(!mycal.book(overlap.first, overlap.second)) return false;
            }
        }
        dict.emplace_back(start, end);
        return true;
    }
    
private:
    pair<int, int> getOverLapped(pair<int, int>& p1, int s, int e){
        return {max(s, p1.first), min(e, p1.second)};
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */