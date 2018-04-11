/* 799. Champagne Tower
 * The idea is simple: we just need to calculate and simulate the process from the first row
 * when wine goes through glass, it may keep 1 cup for itself if there is enough wine.
 */

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured == 0) return 0.0;
        // We just simulate the process from the first row
        vector<double> glasses(query_row+1, 0);
        glasses[0] = poured;
        for(int i = 1; i <= query_row; i++){
            for(int j = i; j >= 0; j--){
                // wine from top-right glass
                glasses[j] = 0.5*(glasses[j] > 1? glasses[j]-1: 0);
                // wine from to-left glass
                if(j > 0) glasses[j] += 0.5*(glasses[j-1] > 1? glasses[j-1] - 1: 0);
            }
        }
        return min(1.0, glasses[query_glass]);
    }
};