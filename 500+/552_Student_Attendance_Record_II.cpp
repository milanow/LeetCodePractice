/* 552. Student Attendance Record II
 * A dp solution, where should consider P, L, A seperately. Initially we have 4 dp array
 * P[i], L[i], A[i] & Total[i], indicating number of sequence ending with P, L, A
 * obviously, Total[i] = P[i] + L[i] + A[i];
 * P[i] = P[i-1] + L[i-1] + A[i-1] (i > 0)
 * L[i] = (A[i-1] + P[i-1])(last char is not 'L') + (A[i-2] + P[i-2])(last char is 'L')
 * for A[i] we should have A[i] = noAP[i-1] + noAL[i-1] (no means perviously dont have 'A')
 * where noAL[i] = noAP[i-1] + noAP[i-2];
 *       noAP[i] = noAP[i-1] + noAL[i-1];
 * Then we have all the fomulas needed
 * To simplify,
 * P[i] = P[i-1] + A[i-1] + L[i-1];
 * L[i] = A[i-1] + P[i-1] + A[i-2] + P[i-2];
 * A[i] = A[i-1] + A[i-2] + A[i-3];
 * here we go
 */
 
class Solution {
public:
    int checkRecord(int n) {
        int base = 1000000007;
        int *A = new int [n];
        int *P = new int [n];
        int *L = new int [n];
        
        P[0] = 1;
        L[0] = 1;
        L[1] = 3;
        A[0] = 1;
        A[1] = 2;
        A[2] = 4;
        
        if(n == 1) return 3;
        
        for(int i = 1; i < n; i++)
        {
            A[i - 1] %= base;
            P[i - 1] %= base;
            L[i - 1] %= base;
            
            P[i] = ((A[i - 1] + P[i - 1]) % base + L[i - 1]) % base;
            
            if(i > 1) L[i] = ((A[i - 1] + P[i - 1]) % base+ (A[i - 2] + P[i - 2]) % base) % base;
            
            if(i > 2) A[i] = ((A[i - 1] + A[i - 2]) % base + A[i - 3]) % base;
        }
        
        return ((A[n - 1] % base + P[n - 1] % base) % base+ L[n - 1] % base) % base;
    }
};