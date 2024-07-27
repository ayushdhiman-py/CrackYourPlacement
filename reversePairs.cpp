class Solution {
    void merge(vector<int> &v, int start, int mid, int end){
        vector<int> temp;
        int low = start, high = mid+1;

        while(low<=mid && high<=end){
            if(v[low]<v[high]){
                temp.push_back(v[low]);
                low++;
            }
            else{
                temp.push_back(v[high]);
                high++;
            }
        }
        while(low<=mid){
            temp.push_back(v[low]);
            low++;
        }
        while(high<=end){
            temp.push_back(v[high]);
            high++;
        }
        for(int i=start; i<=end; i++){
            v[i]=temp[i-start];
        }
    }
    int countpairs(vector<int> &v, int start,int mid, int end){
        int count=0;
        int right=mid+1;
        for(int i=start; i<=mid; i++){
            while(right<=end && v[i] > 2.0*v[right]) right++;
            count+=(right-(mid+1));
        }
        return count;
    }
    int mergeSort(vector<int> &v, int start,int end){
        int count=0;
        if(start>=end) return count;
        int mid = start + (end-start) / 2;
        count+=mergeSort(v,start,mid);
        count+=mergeSort(v,mid+1,end);
        count+=countpairs(v,start,mid,end);
        merge(v,start,mid,end);
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};