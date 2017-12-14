/* 468. Validate IP Address
 * Seprate IPv4 validation with IPv6 validation
 * If we find a '.', then pass it to IPv4 validation. Otherwise pass
 * it to IPv6 validation
 */

public class Solution {
    public string ValidIPAddress(string IP) {
        int len = IP.Length;
        if(len < 7) return "Neither";
        
        string res = "Neither";
        for(int i = 0; i < 5; i++){
            if(IP[i] == '.'){
                res = validIPV4(IP);
                break;
            }else if(IP[i] == ':'){
                res = validIPV6(IP);
                break;
            }
        }
        return res;
    }
    
    string validIPV4(string ip){
        var strs = ip.Split(new char[1]{'.'});
        
        if(strs.Length != 4) return "Neither";
        for(int i = 0; i < 4; i++){
            if(strs[i].Length == 0 || strs[i].Length > 3) return "Neither";
            
            if(strs[i][0] == '0' && strs[i].Length > 1) return "Neither";
            
            int res = 0;
            for(int j = 0; j < strs[i].Length; j++){
                if(strs[i][j] < '0' || strs[i][j] > '9') return "Neither";
                
                res *= 10;
                res += strs[i][j] - '0';
                if(res > 255) return "Neither";
            }
        }
        
        return "IPv4";
    }
    
    string validIPV6(string ip){
        var strs = ip.Split(new char[1]{':'});
        
        if(strs.Length != 8) return "Neither";
        for(int i = 0; i < 8; i++){
            if(strs[i].Length == 0 || strs[i].Length > 4) return "Neither";
            
            for(int j = 0; j < strs[i].Length; j++){
                if(strs[i][j] >= '0' && strs[i][j] <= '9' ||
                  strs[i][j] >= 'a' && strs[i][j] <= 'f' ||
                  strs[i][j] >= 'A' && strs[i][j] <= 'F') continue;
                else return "Neither";
            }
        }
        
        return "IPv6";
    }
}