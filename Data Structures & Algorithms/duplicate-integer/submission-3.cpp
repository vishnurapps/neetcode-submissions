class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> num_map;
        for (int num : nums) {
            if(num_map.find(num) != num_map.end()){
                return true;
            } else {
                num_map[num] = 1;
            }
        }
        return false;
    }
};