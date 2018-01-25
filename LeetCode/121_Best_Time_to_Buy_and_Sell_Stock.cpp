#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        
        int MIN = *max_element(prices.begin(), prices.end());
        int MAX = 0;
        int result = 0, idx_max = prices.size()-1 ;
       
        for(int i = prices.size()-1; i>=0 ; i--){
            if(MAX < prices[i] && i != 0) { MAX = prices[i]; idx_max = i; }
            else if(result < MAX - prices[i]) {
                result = MAX - prices[i];
            }
        }
        if(result<0) result =0;
        return result;
    }
};