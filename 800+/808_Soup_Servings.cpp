/* 808. Soup Servings
 * This solution is from Leetcode forum,
 * When N is larger than 4800, the possibility has been increased where 1 - possibility < 10^-6
 * So according to the description, we just need to return 1.
 * The rest part is a dp process, we notice that each serving is a multiple of 25,
 * so to simplify, we divide 25 to original N to make the dp array smaller
 */.

class Solution {
    double mem[200][200];
public:
    double soupServings(int N) {
        return N >= 4800? 1: f((N + 24) / 25, (N + 24) / 25);
    }
    
    double f(int a, int b){
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1;
        if(b <= 0) return 0;
        if(mem[a][b] > 0) return mem[a][b];
        return mem[a][b] = 0.25 * (f(a-4, b)+f(a-3, b-1)+f(a-2, b-2)+f(a-1, b-3));
    }
};