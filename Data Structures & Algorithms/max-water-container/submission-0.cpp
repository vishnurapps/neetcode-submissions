class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int area = 0;
        while(left < right){
            int new_area = min(heights[left], heights[right])*(right-left);
            area = max(new_area, area);
            if(heights[left]<heights[right]){
                left++;
            } else {
                right--;
            }
        }
        return area;
    }
};
