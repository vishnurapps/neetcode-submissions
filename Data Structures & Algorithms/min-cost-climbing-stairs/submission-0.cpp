class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int one_back = 0;
        int two_back = 0;

        for(int i = 2; i <= cost.size(); i++){
            int min_cost = min(one_back+cost[i-2], two_back+cost[i-1]);
            one_back = two_back;
            two_back = min_cost;
        }
        return two_back;
    }
};
