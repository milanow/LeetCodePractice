/*There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.

Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.

If there isn't such day, output -1.
*/

// 

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> st;
        for(int i = 0; i < flowers.size(); ++i){
            int tar = flowers[i];
            auto it = st.insert(tar).first;
            if(it != st.begin()){
                if(tar-*(--it) == k+1) return i+1;
                ++it;
            }
            if(++it != st.end() && *it-tar == k+1) return i+1; 
        }
        return -1;
    }

        // One C# solution, but TLE
//         SortedSet<int> st = new SortedSet<int>();
//         SortedSet<int> tmp;
        
//         for(int i = 0; i < flowers.Length; ++i){
//             int tar = flowers[i];
//             tmp = st.GetViewBetween(tar, tar+k+1);
//             if(tmp.Count == 1 && tmp.Contains(tar+k+1)) return i+1;
//             tmp = st.GetViewBetween(tar-k-1, tar);
//             if(tmp.Count == 1 && tmp.Contains(tar-k-1)) return i+1;
            
//             st.Add(tar);
//         }
//         return -1;
};