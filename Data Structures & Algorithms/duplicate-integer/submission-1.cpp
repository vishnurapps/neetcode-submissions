class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s1;
        
        for(int num: nums){
            s1.insert(num);
        }

        return(s1.size() != nums.size());

    }
};