/* 789. Escape The Ghosts
 * Ghost or player can wait. Obviously as player you don't want to wait
 * because ghost may chase you.
 * The best strategy for ghost is to go ahead to destination and wait for player
 * If the distance of a single ghost to destination is not greater than distance
 * from player to destination. Then the player cannot escape because ghost can always
 * reach the destination ahead of player.
 *
 * For every single ghost, absolute destination is for sure the judgement if the ghost
 * can catch player. However, I haven't found any persuasive evidence showing that
 * if ghost can coorperate together, waiting at destination is still the best strategy
 */

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int d = abs(target[0]) + abs(target[1]);
        for(auto g: ghosts)
            if (d >= abs(target[0] - g[0]) + abs(target[1] - g[1]))
                return false;
        return true;
    }
};
