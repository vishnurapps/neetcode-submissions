class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right){
            int result = numbers[right] + numbers[left];
            if (result == target){
                    return vector<int>{left+1,right+1};
            } else if (result > target) {
                    right--;
            } else {
                    left++;
            }
        }
    }
};
