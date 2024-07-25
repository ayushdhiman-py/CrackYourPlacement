class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int total = 0, ls = 0, rs = 0, n = nums.size();
        for (int i = 0; i < k; i++) {
            ls += nums[i];
        }
        total=ls;
        int rindx = n - 1;
        for(int i=k-1; i>=0; i--){
            ls-=nums[i];
            rs+=nums[rindx--];
            total=max(total,ls+rs);
        }
        return total;
    }
};
