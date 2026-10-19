class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix[0].size();
        int col_size = matrix.size();
        int left = 0;
        int right = row_size*col_size-1;

        while(left <= right){
            int mid = left + (right - left)/2;
            int row = mid/row_size;
            int col = mid%row_size;

            if(target == matrix[row][col]){
                return true;
            } else if (target < matrix[row][col]){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};
