class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        int m = s1.length();
        int n = s2.length();

        // all elements of s1 has to be present in s2
        if(m > n){
            return false;
        }

        for(int i = 0; i < m; i++){
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        // This becomes equal if the all elements of s1 is present
        // in s2, but in different order/ same order.
        if(freq1 == freq2){
            return true;
        }

        for(int i = m; i < n; i++){

            // We continue with updating the frequency in freq2.
            // But as the length of s1 is m, we need to remove the
            // frequency of elements m elements earlier for them to match
            freq2[s2[i] - 'a']++;
            freq2[s2[i-m] - 'a']--;

            if(freq1 == freq2){
                return true;
            }
        }

        return false;
    }
};
