/* 495. Teemo Attacking
 * Two pointer problem, pre represents previous time where Ashes is not poisoned, 
 * now represents current poison will end at "now"
 * total represents the total poisoned time.
 */



class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0) return 0;
        // pre represents previous time where Ashes is not poisoned, now represents current poison will end at "now"
        int total = 0, pre = timeSeries[0]-1, now = timeSeries[0] + duration - 1;
        for(int i = 1; i < timeSeries.size(); i++){
            if(timeSeries[i] > now){
                total += now - pre;
                pre = timeSeries[i]-1;
            }
            now = timeSeries[i] + duration - 1;
        }
        total += now - pre;
        return total;
    }
};