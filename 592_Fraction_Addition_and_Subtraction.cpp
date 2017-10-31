/* 592. Fraction Addition and Subtraction
 * Straightfoward, but if you don't know __gcd(a,b) in C++ (like me), you may spend time
 * implementing one, it's not hard but....
 */

class Solution {
public:
    string fractionAddition(string expression) {
        int A = 0, B = 1, a, b;
        istringstream iss(expression);
        char c;
        while(iss >> a >> c >> b){
            A = A*b + B*a;
            B *= b;
            int g = abs(__gcd(A, B));
            A /= g;
            B /= g;
        }
        return to_string(A) + '/' + to_string(B);
    }
};