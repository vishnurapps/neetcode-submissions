class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        if(store.find(key) == store.end()){
            return "";
        }

        vector<pair<int, string>>& value = store[key];

        int left = 0;
        int right = value.size() - 1;

        string answer = "";
        while(left <= right){
            int mid = left + (right - left)/2;

            if(value[mid].first <= timestamp){
                answer = value[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return answer;
    }
};
