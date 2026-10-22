class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // We are creating a frequency counter and update frequency
        unordered_map<int,int> freq;
        for(int num: nums){
            freq[num]++;
        }

        // We create a bucket to store the frequency 
        // Bucket size is num.size()+1 because a vector could be
        // full of same elements.
        vector<vector<int>> bucket(nums.size()+1);

        for(auto &p: freq){
            int num = p.first;
            int count = p.second;
            // Push to bucket based on count
            bucket[count].push_back(num);
        }

        vector<int> result;
        for(int i = bucket.size()-1; i >= 0 && result.size() < k; i-- ){
            for(int num: bucket[i]){
                result.push_back(num);

                if(result.size() == k){
                    break;
                }
            }
        }

        return result;
        
    }
};
