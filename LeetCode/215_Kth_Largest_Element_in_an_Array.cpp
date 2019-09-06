class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        qsort( nums,0,nums.size()-1 );
        
        return nums[nums.size()-k];
    }
    
    void qsort(vector<int>& nums, int L, int R){
        int pivot = L;
        int j = pivot;
        int i = j+1;
        
        if(L<R){
            for(; i <= R ; i++){
                if(nums[i]<nums[pivot]){
                    j++;
                    swap(nums[i],nums[j]);
                }
            }
            swap(nums[j],nums[L]);
            
            qsort(nums,j+1,R);
            qsort(nums,L,j-1);
        
        }
    }
};