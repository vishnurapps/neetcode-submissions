class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            } else {
                //If mid is not greater that right, we could be in middle
                right = mid;
            }
        }
        //You can return nums of right or left both will point to same
        return nums[left];
    }
};
