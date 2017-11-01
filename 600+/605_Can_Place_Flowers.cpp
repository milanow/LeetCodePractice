/* 605. Can Place Flowers
 * One of the benefit writing leetcode practice in C++ is:
 * 'vector'
 * With vector we can simply change the original array by adding two
 * zero at the beginning and end,
 * to meet the corner cases that 0,0,1 can actually plant 1 flower as
 * 1,0,1, but 1,0,0,1 cannot plant flower.
 * in the end, we found 0,0,0 can be planted a flower in the middle.
 * jsut iteratively check it and minus n by 1.
 * return true if n <= 0, means there is enough place to plant
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for(int i = 1; i < flowerbed.size()-1; ++i){
            if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0){
                --n;
                ++i;
            }
        }
        return n <= 0;
    }
};