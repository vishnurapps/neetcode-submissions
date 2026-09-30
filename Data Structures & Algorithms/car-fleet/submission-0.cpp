class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;

        for(int i = 0; i < position.size(); i++){
            double time = double(target-position[i])/speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.rbegin(), cars.rend());
        stack<double> fleet;
        for(pair<int, double> car: cars){
            if(fleet.empty() || fleet.top()<car.second){
                fleet.push(car.second);
            }
        }
        return fleet.size();
    }
};
