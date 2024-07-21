class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> check(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            if(check[nums[i]] > 0) {
                return nums[i];
            }
            check[nums[i]]++;
        }
        return 0;
    }
};
