class Solution {
public:
    bool canFinish(vector<int>&piles, int speed, int hours){
        int time = 0;
        for(int pile: piles){
            int carry = 0;
            time += pile/speed;
            carry = pile%speed;
            if (carry !=0){
                time++;
            }
            if(time > hours){
                return false;
            }
        }
        return true;
        
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        //maximum speed is 4 -> finish in 4 hours
        //minimum speed is 1 -> finish in 10 hours
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while(left <= right){
            int mid = left + (right - left)/2;
            
            if(canFinish(piles, mid, h)){
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
