class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int m = n%2==0 ? (nums[n/2]+nums[n/2-1])/2 : nums[n/2];
        int steps = 0;
        for(auto num:nums){
            steps+=abs(num-m);
        }
        return steps;
    }
};