class TimeMap {
    
private:
    unordered_map<string, vector<pair<string, int>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }

        vector<pair<string,int>>& value = mp[key];
        int left = 0;
        int right = value.size() - 1;
        string answer = "";
        while(left <= right){
            int mid = left + (right - left)/2;
            if(value[mid].second <= timestamp){
                answer = value[mid].first;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return answer;
    }
};
