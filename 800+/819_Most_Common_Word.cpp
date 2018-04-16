/* 819. Most Common Word
 * Firstly, of course to count the frequency of the words in paragraph,
 * Maintain a priority queue to pop out the highest frequency's word
 * If it is not on the banned list, when that is the result
 */

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        auto comp = [](const pair<string, int>& p1, const pair<string, int>& p2){
            return p1.second < p2.second;
        };
        
        unordered_map<string, int> dict;
        int idx = 0, len = paragraph.length();
        while(idx < len){
            while(idx < len && !isalpha(paragraph[idx])) idx++;
            string str("");
            while(idx < len && isalpha(paragraph[idx])){
                str.append(1, tolower(paragraph[idx++]));
            }
            if(str != "") dict[str]++;
        }
        
        unordered_set<string> st(banned.begin(), banned.end());
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(dict.begin(), dict.end(), comp);
        string res;
        while(!pq.empty()){
            if(st.find(pq.top().first) == st.end()) return pq.top().first;
            // res += pq.top().first + ", ";
            pq.pop();
        }
        return "";
    }
};