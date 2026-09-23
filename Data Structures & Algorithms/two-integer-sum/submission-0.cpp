class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> result;
        for (int i = 0; i < nums.size(); i++){
            int search_term = target-nums[i];
            if (result.find(search_term) != result.end()){
                return {result[search_term],i};
            } 
            result[nums[i]] = i;
        }
        return {};
    }
};
