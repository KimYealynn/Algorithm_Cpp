class Solution {
#include <algorithm>
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result, tmp = nums;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1, a = nums[i] , b = nums[j];
        
        while(i!=j){
            if( a+b == target) break;
            
            if(b > target) j--;
            else if (a+b < target) i++;
            else if (a+b > target) j--;
            a = nums[i];
            b = nums[j];
        }
        
        for(int x=0; x<tmp.size(); x++){
            if(tmp[x]==a) result.push_back(x);
            else if(tmp[x]==b) result.push_back(x);
        }
        sort(result.begin(), result.end());
        return result;
    }
};