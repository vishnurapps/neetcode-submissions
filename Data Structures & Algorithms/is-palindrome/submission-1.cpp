class Solution {
public:
    bool isPalindrome(string s) {

     int left = 0;
     int right = s.size()-1;

     // Transform the upper cases to lower cases.
     std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
     while(left <= right){
        
        // Use isalnum to see if its alpha numeric
        if(!isalnum(static_cast<unsigned char>(s[left]))){
            left++;
            continue;
        }
        if(!isalnum(static_cast<unsigned char>(s[right]))){
            right--;
            continue;
        }
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
     }
     return true;
     
    }
};
