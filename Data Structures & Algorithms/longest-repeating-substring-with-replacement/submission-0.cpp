class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;

        for(int right = 0; right < s.length(); right++){
            // We build up the frequency on every iteration
            freq[s[right] - 'A']++;

            //Find max frequency on every iteration as it changes
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Widow length is fixed like below
            int windowLength = right - left + 1;

            //Everytime we find the replacements.
            int replacements = windowLength - maxFreq;

            // We are allowed only k replacements. If the replacements
            // increase, we reduce the frequency of the element in left side.
            // and increment left. Why ? Because we are shrinking the window
            // by increasing left. So we reduced the frequency.
            if(replacements > k){
                freq[s[left] - 'A']--;
                left++;
            }
            // There would have been a previous max length. So we are considering
            // that and current length.
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
