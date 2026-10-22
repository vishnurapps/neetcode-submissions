class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,1);
        // Prefix product is the product of all numbers before
        // the index. As there is no number before index 0, we start
        // with 1
        int prefix = 1;
        for(int i = 0; i < n; i++){
            result[i] = result[i]*prefix;
            prefix = prefix*nums[i];
        }

        // Suffix product is the product of all numbers after 
        // the index. As there is no number before index 0, we start
        // with 1
        int suffix = 1;
        for(int i = n-1; i >=0; i--){
            result[i] = result[i]*suffix;
            suffix = suffix*nums[i];
        }

        return result;
    }
};
