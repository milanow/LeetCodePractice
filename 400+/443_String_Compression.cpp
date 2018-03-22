/* 443. String Compression
 * Two pointer solution
 * The slower pointer is to assign new array 
 * The faster pointer is to check old array's information
 */

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() <= 1) return static_cast<int>(chars.size());
        int a = 0, b = 1, cnt = 1;
        for(; b <= chars.size(); b++){
            if(b == chars.size() || chars[a] != chars[b]){
                if(cnt > 1){
                    int digits = 0, num = cnt;
                    while(num > 0){
                        num /= 10;
                        digits++;
                    }
                    
                    int i = a + digits;
                    while(cnt > 0){
                        chars[i--] = cnt % 10 + '0';
                        cnt /= 10;
                    }
                    a += digits + 1;
                }else{
                    a += 1;
                }
                if(b != chars.size()) chars[a] = chars[b];
                cnt = 1;
            }else{
                cnt++;
            }
        }
        return a;
    }
};