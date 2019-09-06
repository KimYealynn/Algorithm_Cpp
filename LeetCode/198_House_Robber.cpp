class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size==0)
            return 0;
        if(size==1)
            return nums[0];
        if(size==2)
            return nums[0]>=nums[1]?nums[0]:nums[1];
        
        vector<int> dp;
        int i = 1;
        
        dp.push_back(nums[0]);
        dp.push_back(nums[1]);

        while ( ++i < size ){
            int num = dp[i-1] >= dp[i-2]+nums[i] ? dp[i-1] : dp[i-2]+nums[i];
            num = num >= dp[i-3]+nums[i] ? num : dp[i-3]+nums[i];
                
            dp.push_back(num);
        }
        
        return dp[size-1];
    }
};