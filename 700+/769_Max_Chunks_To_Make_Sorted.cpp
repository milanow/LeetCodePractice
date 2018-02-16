/* 769. Max Chunks To Make Sorted
 * This is much more like a greedy algorithm
 * to make the whole chunk can be sorted, every chunk has to contain the elements
 * which is not out of the range of its position
 * e.g. the first chunk (size = n) has to contain all the elements of [0,n-1]
 * We just need to check how can we divide the chunk as small as possible by
 * greedily 'cut' the chunk. (if current max of subchunk + 1 == st.size() then 
 * it can be an individual chunk)
 */

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_set<int> st;
        int res = 0, curmx = 0;
        for(int i = 0; i < arr.size(); i++){
            st.insert(arr[i]);
            if(arr[i] > curmx){
                curmx = arr[i];
            }
            if(curmx + 1 == st.size()) res++;
        }
        return res;
    }
};