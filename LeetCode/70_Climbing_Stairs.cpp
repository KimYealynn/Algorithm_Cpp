class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        
        int keep[n+1]= {0,1,2,} ,i = 2;
        
        while(++i<=n){
            keep[i] = keep[i-1]+keep[i-2]; 
        }
        return keep[n];
    }
};