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

            // This is the maximum we can reach. Add i + number in ith index
            farthest = max(farthest, i+nums[i]);

            // If farthest is reaching more than the size of the array,
            // we reached the end.
            if(farthest >= nums.size() - 1){
                return true;
            }
        }
        return true;
    }
};
