class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        int cut_num = 1, x;
        
        result.push_back(0);
        if(num==0) return result;
        result.push_back(1);
        if(num==1) return result;
        
        for(int i=2; i<=num; i++){
            x = 1;
            if(i==cut_num*2) {
                cut_num = i;
                result.push_back(1);            
            }
            else{
                result.push_back(result[i-cut_num] + x);
            }
        }
        return result;
    }
};