class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> temp;
        for(string str: strs){
            int count[26] = {0};
            for(int i = 0;  i < str.length(); i++){
                count[str[i]-'a']++;
            }
            string key;
            for(int i: count){
                key += to_string(i)+"#";
            }
            // cout << key << endl;
            temp[key].push_back(str);
        }
        vector<vector<string>> result;
        for(pair <string, vector<string>> p: temp){
            result.push_back(p.second);
        }
        return result;
    }
};
