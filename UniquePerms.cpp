class Solution {
    public:
    int bit = 0;
    void solve(vector<int>&arr , vector<int>&temp , set<vector<int>>&s , int n){
        if(bit == ( (1<<n) - 1) ) {
            s.insert(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if( (bit & (1<<i)) == 0){
                temp.push_back(arr[i]);
                bit = bit ^ (1<<i);
                solve(arr,temp,s,n);
                temp.pop_back();
                bit = bit ^ (1<<i);
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<int>temp;
        set<vector<int>>s;
        vector<vector<int>>ans;
        solve(arr,temp,s,n);
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};