class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int l, r, m, N, sum;
        sort(nums.begin(), nums.end());
        N = nums.size();
        
        l = 0;
        while (l < N-2) {
            if (l != 0 && (nums[l] == nums[l-1])){
                l++; continue;
            }
            
            m = l+1; r = N-1;
            while (m < r) {
                sum = nums[l] + nums[m] + nums[r];
                if (sum == 0)
                    ans.push_back({nums[l], nums[m], nums[r]});
                if (sum <= 0) {
                    m++;
                    while(nums[m-1]==nums[m] && m < r)
                    m++;
                }
                if (sum >= 0) {
                    r--;
                    while(nums[r+1]==nums[r] && m < r)
                    r--;
                }   
            }
            l++;
        }
        return ans;
    }
};

