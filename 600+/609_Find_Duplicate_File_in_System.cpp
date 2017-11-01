/* 609. Find Duplicate File in System
 * A map to record the files' path according to content
 * then parse every input indivisualy and save it to map
 * print out thoes saved values to vector result
 */

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        
        for(auto path: paths){
            stringstream ss(path);
            string files;
            string root;
            getline(ss, root, ' ');
            while(getline(ss, files, ' ')){
                auto pos = files.find('(');
                string filename = root + "/" + files.substr(0, pos);
                string content = files.substr(pos+1, files.find(')') - pos - 1);
                mp[content].push_back(filename);
            }
        }
        
        for(auto& p: mp){
            if(p.second.size() > 1) res.push_back(p.second);
        }
        return res;
    }
};