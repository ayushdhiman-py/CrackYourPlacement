class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int it = 0; it < nums.size(); it++) {
            if (it > 0 && nums[it] == nums[it - 1]) continue; // Skip duplicates in the outer loop

            int i = it + 1, j = nums.size() - 1;
            while (i < j) {
                int sum = nums[it] + nums[i] + nums[j];
                if (sum == 0) {
                    res.push_back({nums[it], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) i++; // Skip duplicates in the inner loop
                    while (i < j && nums[j] == nums[j - 1]) j--; // Skip duplicates in the inner loop
                    i++;
                    j--;
                } else if (sum < 0) {
                    i++;
                } else {
                    j--;
                }
            }
        }

        return res;
    }
};
