class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum=nums[0]; 
        int maxEnding[n];
        maxEnding[0]=nums[0];
        for(int i = 1 ; i < n;i++ ){
            maxEnding[i]=max(maxEnding[i-1]+nums[i],nums[i]);
            maxSum = max(maxEnding[i],maxSum);
        }
        
        return maxSum;
    }
};
