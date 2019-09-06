class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        string r = s;
        reverse(s.begin(), s.end());
        int num=0;
        int MAT[len+1][len+1]={};
        
        for(int i=0; i<=len; i++){
            for(int j=0; j<=len; j++){
                if(i==0 || j==0) 
                    MAT[i][j] = 0;
                else if(s[i-1]==r[j-1])
                    MAT[i][j] = MAT[i-1][j-1]+1;
                else
                    MAT[i][j] = max(MAT[i-1][j],MAT[i][j-1]);
                
                num = max(MAT[i][j], num);
            }
        }
        
        return num;
    }
};