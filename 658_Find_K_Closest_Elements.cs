/* 658. Find K Closest Elements
 * THe core idea is 'Sliding Window', keep maintaining a queue with length of k where storing
 * the best candidates. Replacing candidate by comparing absolute length between element and k,
 * if incomming element's distance with k is less, then Dequeue the next element of queue and 
 * Enqueue to new candidate
 */


public class Solution {
    public IList<int> FindClosestElements(int[] arr, int k, int x) {
        Queue<int> que = new Queue<int>();
        for(int i = 0; i < arr.Length; ++i){
            if(que.Count < k) que.Enqueue(arr[i]);
            else{
                // the incomming element is a better candidate
                if(Math.Abs(que.Peek() - x) >　Math.Abs(arr[i] - x)){
                    que.Enqueue(arr[i]);
                    que.Dequeue();
                } 
            }
        }
        
        // var res = new List<int>();
        // while(que.Count > 0){
        //     res.Add(que.Dequeue());
        // }
        return que.ToList<int>();
        
    }
}