/* 751. IP to CIDR
 * The solution contains several steps
 * 1. convert string ip to a 32-bits number
 * 2. find possible room that can fill ips by counting how many tailing zero of n
 * 3. check how many rooms need by comparing it with range
 * 4. make an answer by passing it to putb() function
 * 5. repeat 2-4 until range is filled
 */

class Solution {
    vector<string> ans;
    void putb(uint32_t num, int r) {
        string b;
        int i = 4;
        while (i-- > 0) {
            b = to_string(num % 256) + b;
            if (i)
                b = "." + b;
            num >>= 8;
        }
        b += "/" + to_string(r);
        ans.push_back(b);
    }
public:
    vector<string> ipToCIDR(string ip, int range) {
        uint32_t n = 0;
        int s = 0, e = 1, i = 0;
        while (e <= ip.length()) { // convert ip into 32 bit unsigned integer
            if (e == ip.length() || ip[e] == '.') {
                n += stoi(ip.substr(s, e-s)) * (1 << (24 - (8 * i++)));
                s = e + 1;
            }
            e++;
        }
        while (range > 0) {
            // find room using tailing zeros
            uint32_t temp = n, room = 1;
            while (temp % 2 == 0) {
                room <<= 1;
                temp >>= 1;
            }
            // find possible usage of room
            uint32_t take=1;
            int r=32;
            temp = range < room ? range : room;
            while (temp > 1) {
                take <<= 1;
                r--;
                temp >>= 1;
            }
            
            // insert n/r into ans list
            this->putb(n, r);
            
            // modify n & range
            n += take;         
            range -= take;
        }
        return ans;
    }

};