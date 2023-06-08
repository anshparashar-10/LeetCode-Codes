class Solution {
public:
    int normalSubarraySum(vector<int>& arr){
        int n = arr.size();
        int maxEnding[n];
        int res=arr[0];
        maxEnding[0]=arr[0];
        for(int i =1 ;i <n;i++){
            maxEnding[i]=max(maxEnding[i-1]+arr[i],arr[i]);
            res = max(maxEnding[i],res);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int normalSum = normalSubarraySum(nums);
        if(normalSum<0){
            return normalSum;
        }
        int arr_sum = 0;
        for(int i= 0 ; i<nums.size();i++){
            arr_sum+=nums[i];
            nums[i]=-nums[i];
        }
        int circularSum = arr_sum + normalSubarraySum(nums);
        return max(circularSum,normalSum);
    }
};
