class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i <= heights.size(); i++){
            
            int currentHeight = (i == heights.size()) ? 0: heights[i];

            while(!st.empty() && currentHeight < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                int width = right - left - 1;
                int area = height * width;
                maxArea = max(maxArea, area);
            }
            st.push(i);

        }
        return maxArea;
    }
};
