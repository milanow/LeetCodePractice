/* 535. Encode and Decode TinyURL
 * 1. Mapping longUrl into a number
 * 2. use the number to generate specific shortUrl (length = 6)
 * 3. Save it to hashmap
 */

class Solution {
    const string dict = "01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    int cnt = 0;
    unordered_map<string, string> ltos;
    unordered_map<int, string> stol;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(ltos.find(longUrl) != ltos.end()) return ltos[longUrl];
        string code = "";
        int num = ++cnt;
        while(num > 0){
            code = dict[num%62] + code;
            num /= 62;
        }
        
        while(code.length() < 6){
            code = '0' + code;
        }
        
        ltos[longUrl] = code;
        stol[cnt] = longUrl;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int tarid = 0;
        for(int i = 0; i < shortUrl.length(); ++i){
            tarid = tarid*62 + (int)(dict.find(shortUrl[i]));
        }
        if(stol.find(tarid) != stol.end()) return stol[tarid];
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));