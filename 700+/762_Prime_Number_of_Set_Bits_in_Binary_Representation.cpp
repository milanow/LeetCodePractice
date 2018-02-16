/* 762. Prime Number of Set Bits in Binary Representation
 * Since L <= R and L, R -> [1, 10^6], so all possible primes cannot be large than 29
 * Just iterating through L to R and count the number of '1' bits for each numbers
 * To see if the number of bits resides in prime set
 */

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> primest = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int res = 0;
        for(int i = L; i <= R; i++){
            int cnt = 0, j = i;
            while(j > 0){
                if(j & 1) cnt++;
                j >>= 1;
            }
            if(primest.find(cnt) != primest.end()) res++;
        }
        return res;
    }
};