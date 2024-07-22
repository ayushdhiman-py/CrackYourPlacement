class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numsSize = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0; i<numsSize; i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                auto a = mpp.find(target-nums[i]);
                return {a->second, i};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};