/* 517. Super Washing Machines
 * Firstly we need to check if this machines array can possibly be equally
 * assigned same number of clothes.
 * Then to find out the min steps needed, we should find out what is the limitation
 * of "flatting" the machines. 
 * Some machines requires clothes, some machines need move clothes out
 * For each machine, the machines to left and machines to right need it to "pass"
 * clothes from left to right or right to left.
 * Thus it is important to know how many clothes left(right) need/remain
 * "ballence" is a variable to record the value. it represents gain/lose of the clothes.
 * From this point the answer would be max(every value of ballence)
 * However, consider another limitation, each machine can only send out one cloth
 * each time. Thus we need to check machines[i] - average as the lower_bound.
 * We don't need to check average - machines[i] because in this case, the
 * machine is receiving from other machines. A machine can receive multiple clothes
 * per step, but can only send one cloth per step.
 */

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        // check validation
        int sum = 0, n = machines.size();
        for(int i = 0; i < n; i++){
            sum += machines[i];
        }
        if(sum % n != 0) return -1;
        int avg = sum / n;
        
        int sum2 = 0, mnstep = 0, ballence = 0;
        for(int i = 0; i < n; ++i){
            ballence += machines[i] - avg;
            mnstep = max(mnstep, max(abs(ballence), machines[i] - avg));
        }
        return mnstep;
    }
};