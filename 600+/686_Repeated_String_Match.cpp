/* 686. Repeated String Match
 * The solution is intuitive, using cycle array by % A.size()
 * to check how many repeated A can be long enough to hold B
 * NOTE: The "check substr" function is using brute force
 */

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        for (auto i = 0, j = 0; i < A.size(); ++i) {
            for (j = 0; j < B.size() && A[(i + j) % A.size()] == B[j]; ++j);
            if (j == B.size()) return (i + j) / A.size() + ((i + j) % A.size()? 1 : 0);
        }
        return -1;
    }
};