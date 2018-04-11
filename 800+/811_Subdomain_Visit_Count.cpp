/* 811. Subdomain Visit Count
 * Iterating all string in cpdomains and save the counting results into hashmap.
 * For each domain&count, we just need to correctly parse the count and domains
 * Once got correct parsing result, we could save it into hashmap
 */

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> dict;
        for(string& cp: cpdomains){
            istringstream iss(cp);
            string str;
            getline(iss, str, ' ');
            int val = stoi(str);
            vector<string> subdom;
            while(getline(iss, str, '.')){
                subdom.push_back(str);
            }
            for(int i = subdom.size() - 2; i >= 0; i--){
                subdom[i] = subdom[i] + "." + subdom[i+1];
            }
            for(string& dom: subdom){
                dict[dom] += val;
            }
        }
        vector<string> res;
        for(auto& p: dict){
            res.emplace_back(to_string(p.second) + " " + p.first);
        }
        return res;
    }
};