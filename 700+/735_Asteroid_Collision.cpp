/* 735. Asteroid Collision
 * Collide these asteroid step by step.
 * For each iteration, checking if ajacent asteroids could collide.
 * If collided, then mark them as 1001 (an impossible number) as representation
 * of "to be deleted".
 * Repeat the process until the asteroids array reach a stable status
 */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        if(n == 0) return vector<int>();
        
        while(true){
            bool changed = false;
            for(int i = 0, j = 0; i < n-1; i++){
                if(asteroids[i] == 1001) continue;
                j = i+1;
                while(j < n && asteroids[j] == 1001) j++;
                if(j == n) break;
                if(asteroids[i]*asteroids[j] > 0 || asteroids[i] < 0) continue;
                else{
                    if(abs(asteroids[i]) > abs(asteroids[j])){
                        asteroids[j] = 1001;
                    }else if(abs(asteroids[i]) < abs(asteroids[j])){
                        asteroids[i] = 1001;
                    }else{
                        asteroids[i] = asteroids[j] = 1001;
                    }
                    changed = true;
                    i = j-1;
                }
            }
            if(!changed){
                // shrink asteroids here and return
                vector<int> res;
                for(int i: asteroids){
                    if(i != 1001) res.push_back(i);
                }
                return res;
            }
        }
        
        return vector<int>();
    }
};