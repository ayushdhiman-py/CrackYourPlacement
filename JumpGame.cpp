class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind=0;

        int i=0;
        while(i<nums.size()){
            if(i>maxind) return false;
            maxind=max(maxind,i+nums[i]);
            i++;
        }
        return true;
    }
};