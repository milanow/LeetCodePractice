/* 420. Strong Password Checker
 * The problem is REALLY hard, it take me long to figure out how this solution works.
 * 
 * The key is to find out which operation is the most efficient: Replace
 * Let's divide the problem into three conditions:
 * 1. lengthof(s) <= 6
 * 2. 6 < lengthof(s) <= 20
 * 3. lenthof(s) > 20
 * 
 * (1)
 * For first 2 conditions, we don't need to delete any character, instead we can replace
 * characters. Since replacing character is much more efficient. 
 * (e.g., "aaaa", we need to delete two 'a's to make it valid -> "aa", but replace an 'a'
 * to 'b' -> "abaa" only needs one operation)
 * Therefore, we only need "add" and "replace" opeartions. Firstly, we need to check if
 * there are upper/lower/digit characters. Every of them needs one operation to safisty requirements
 * Then we need to find out repeating characters in a row. When we meet an "aaa", how we
 * should deal with it? By adding a character, "aaa"->"aaba", where the last 'a' still needs
 * to be counted as next "aaa" block (that's why l = r in the code). By replacing, "aaa"->"aab",
 * where the last 'a' becomes 'b' and it doesn't need to check the last 'a' anymore (l = r+1 in code)
 * Of course, if we had to adding character to meet length requirements, then we could use
 * these "addTar" to fulfill adding operations. That's why when meeting "aaa", we first
 * check if there is still adTar left (toAdd < addTar).
 * Then just return max of addTar + replace ops and upper/lower/digit ops
 * 
 * (2)
 * For this condition, we need to delete instead of add.
 * First, we save repeating blocks, recording it's length
 * Secondly, for repeating blocks of different length:
 * 1) Try to delete one letter from repetitions with (length % 3) == 0. Each deletion decreases replacement by 1
 * 2) Try to delete two letters from repetitions with (length % 3) == 1. Each deletion decreases repalcement by 1
 * 3) Try to delete multiple of three letters from repetions with (length % 3) == 2. Each deletion (of three 
 * letters) decreases repalcements by 1
 * After deleting one or two letters for 1) and 2), it becomes (length % 3) group, so we need to put it into (length % 3)
 * group if the remaining length is still larger than 2
 * In the end, if there are still delTar left, we replace "replacing operations" to "deleting operations"
 * because we have to delete to meet length smaller than 20 requirement. 
 */


class Solution {
public:
    int strongPasswordChecker(string s) {
        int delTar = max(0, (int)s.length() - 20), addTar = max(0, 6 - (int)s.length());
        int toDel = 0, toAdd = 0, toReplace = 0, needUpper = 1, needLower = 1, needDigit = 1;
        
        // (1)
        for(int r = 0, l = 0; r < s.length(); r++){
            if(islower(s[r])) needLower = 0;
            else if(isupper(s[r])) needUpper = 0;
            else if(isdigit(s[r])) needDigit = 0;
            
            if(r - l == 2){
                if(s[l] == s[l+1] && s[r-1] == s[r]){
                    if(toAdd < addTar){
                        toAdd++;
                        l = r;
                    }else{
                        toReplace++;
                        l = r+1;
                    }
                }else{
                    l++;
                }
            }
        }
        
        if(delTar == 0) return max(addTar + toReplace, needUpper + needLower + needDigit);
        
        //(2)
        toReplace = 0;
        vector<unordered_map<int, int>> mp(3);
        for(int r = 0, l = 0, len; r <= s.length(); r++){
            if(r == s.length() || s[l] != s[r]){
                if ((len = r - l) > 2) { mp[len%3][len]++; } 
                l = r;
            }
        }
        
        for(int i = 0; i < 3; i++){
            for(auto it = mp[i].begin(); it != mp[i].end(); it++){
                if(i < 2){
                    int numDel = i+1, delOps = min(it->second, (delTar - toDel) / numDel);
                    toDel += numDel * delOps;
                    it->second -= delOps;
                    
                    // it becomes new group after deletion
                    if(it->first - numDel >= 3) mp[2][it->first - numDel] += delOps;
                }
                
                // replace operation is always more effective than delete operation
                toReplace += (it->second) * ((it->first)/3);
            }
        }
        
        // if there is remaining delete operations
        int delOps = delTar - toDel;
        // one replace operation = three deleting operations
        toReplace -= (delOps/3);
        
        return delTar + max(toReplace, needUpper + needLower + needDigit);
    }
};