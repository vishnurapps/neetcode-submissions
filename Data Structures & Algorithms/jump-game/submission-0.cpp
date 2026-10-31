class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for(int i = 0; i < nums.size(); i++){
            // i is the current index we are at
            // If farthest is less than that. it means
            // we cant reach the i using the farthest.
            if(i > farthest){
                return false;
            }

            farthest = max(farthest, i+nums[i]);

            if(farthest >= nums.size() - 1){
                return true;
            }
        }
        return true;
    }
};
