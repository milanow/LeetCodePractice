/* 539. Minimum Time Difference
 * Sort the time first, the min distance must resides in difference of adjacent time points
 * plus tailTime - headTime.
 */

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(begin(timePoints), end(timePoints));
        int minDiff = INT_MAX;
        for(int i = 1; i < timePoints.size(); i++){
            minDiff = min(minDiff, timeDiff(timePoints[i-1], timePoints[i]));
        }
        minDiff = min(minDiff, timeDiff(timePoints[(int)timePoints.size()-1], timePoints[0]));
        return minDiff;
        
    }
    
    int timeDiff(string& s1, string s2){
        int time1 = stoi(s1.substr(0, 2))*60 + stoi(s1.substr(3,2));;
        int time2 = stoi(s2.substr(0, 2))*60 + stoi(s2.substr(3,2));
        if(time2 < time1) time2 += 24*60;
        return time2 - time1;
    }    
};