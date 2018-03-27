/* 460. LFU Cache
 * There are three hashmap storing key, value and frequency,
 * kvf: key -> value, frequency, for fast getting the value
 * fk: frequency -> list of keys, because same frequency may have multiple keys
 * ki: key -> list iterator, used for fast deleting iterator in fk
 * In summary we just need to maintain the three data structures in the lifecycle
 * detailed comment below
 */

class LFUCache {
    int cap;
    int mnfreq;
    int sz;
    
    unordered_map<int, pair<int, int>> kvf;
    unordered_map<int, list<int>> fk;
    unordered_map<int, list<int>::iterator> ki;
public:
    LFUCache(int capacity): cap(capacity), mnfreq(0), sz(0) {}
    
    int get(int key) {
        auto it = kvf.find(key);
        if(it == kvf.end()) return -1;
        
        // delete original frequency
        fk[kvf[key].second].erase(ki[key]);
        // add new frequency to fk
        fk[++kvf[key].second].push_back(key);
        // update ki to assign new iterator
        ki[key] = --fk[kvf[key].second].end();
        // if not key for min frequncy, then self-add one because, now frequency must increase at most 1
        if(fk[mnfreq].size() == 0) mnfreq++;
        return kvf[key].first;
    }
    
    void put(int key, int value) {
        if(cap <= 0) return;
        
        // check to see if this key exist
        int val = get(key);
        if(val != -1){
            kvf[key].first = value;
            return;
        }
        
        // larger than capacity
        if(sz >= cap){
            // delete the oldest touched min-freuqncy key, which is the front() of the list in kvf
            kvf.erase(fk[mnfreq].front());
            // delete the key in ki
            ki.erase(fk[mnfreq].front());
            // delete the key in fk
            fk[mnfreq].pop_front();
            sz--;
        }
        
        // add new key value pair, with frequency 1
        kvf[key] = make_pair(value, 1);
        fk[1].push_back(key);
        ki[key] = --fk[1].end();
        // min frequency must be 1 now. it doesn't make sense to have a zero frequency
        mnfreq = 1;
        sz++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */