/* 537. Complex Number Multiplication
 * The key is correctly parsing the complex number...since the input will never be 
 * a-bi (instead it will be a+-bi). We can use istringstream to fill in our values
 */

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        // auto p1 = parseComplexNum(a);
        // auto p2 = parseComplexNum(b);
        // int newcoe = p1.first * p2.first + (-1)*p1.second * p2.second;
        // int newcoe2 = p1.first * p2.second + p1.second * p2.first;
        // return to_string(newcoe) + "+" + to_string(newcoe2) + "i";
        
        int ra, ia, rb, ib;
        char buff;
        stringstream aa(a), bb(b), ans;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
        return ans.str();
    }
    
    // pair<int, int> parseComplexNum(string str){
    //     int a = 0, b = 0;
    //     auto p = str.find_first_of("0123456789", 0);
    //     a = stoi(str.substr(p)) * (p == 0? 1: (str[p-1] == '+'? 1: -1));
    //     p = str.find_first_not_of("0123456789", p);
    //     p = str.find_first_of("0123456789", p);
    //     b = stoi(str.substr(p)) * (str[p-1] == '+'? 1: -1);
    //     return {a, b};
    // }
};