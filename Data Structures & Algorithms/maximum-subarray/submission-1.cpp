class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // We make two variables to hold currentSum and maxSum
        // These variables hold the value of first element
        int currentSum = nums[0];
        int maxSum = nums[0];

        // We considered first element, so start from index 1
        for(int i = 1; i < nums.size(); i++){
            // Add number in current index with current sum
            // check if its larger than the number in current index
            // if current number is large, we can ignore the previous sum 
            // we calculated and consider only the number in current index
            currentSum = max(nums[i], currentSum + nums[i]);

            // The current sum changes everytime, we need track max sum
            maxSum = max(currentSum, maxSum);
        }
        return maxSum;
    }
};
