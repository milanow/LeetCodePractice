/* 722. Remove Comments
 * (This problem is absolutely no fun because it lacks detail)
 * For each line, if we found '/', then we need to check if it is a "/*" or "//"
 * If we found a "/*" we need to find next ’* /‘
 * Else we just save it into out results
 */

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        for(int i = 0; i < source.size(); i++){
            string s = "";
            for(int j = 0; j < source[i].size(); j++){
                if(source[i][j] == '/' && j < source[i].size()-1 && (source[i][j+1] == '/' || source[i][j+1] == '*')){
                    if(source[i][j+1] == '/') break;
                    else{
                        j += 2;
                        if(j == source[i].size()){
                            i++; j = 0;
                        }
                        // find '*/'
                        while(!(source[i][j] == '*' && j < source[i].size()-1 && source[i][j+1] == '/')){
                            if(++j >= source[i].size()){
                                i++;
                                j = 0;
                            }
                        }
                        j += 1;
                    }
                }else{
                    s.append(1, source[i][j]);
                }
            }
            if(s != "") res.push_back(s);
        }
        return res;
    }
};