class Solution {
public:
    int subarraySum(vector<int>& nums, int goal) {
        int n=nums.size();
        int left=0;
        int right=0;
        int sum=0;
        int count=0;
        int temp=0;
        while(right<n){
            sum+=nums[right];
            if(nums[right]==1)temp=0;
            while(sum==goal && left<=right){
                temp++;
                sum-=nums[left];
                left++;
            }
            //When the current sum exceeds the goal reduce it by 1
            if(sum>goal){ 
                sum-=nums[left];
                left++;
            }
            count+=temp;
            right++;
        }
        return count;
    }
};