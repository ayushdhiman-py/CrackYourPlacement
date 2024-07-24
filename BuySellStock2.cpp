class Solution {
    vector<vector<int>> dp;
    int solve(int i , int buy, vector<int> prices){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        long profit = 0;
        if(buy){
            profit=max(-prices[i]+solve(i+1,0,prices), 0 + solve( i+1, 1, prices));
        }
        else{
            profit=max(prices[i]+solve(i+1,1,prices), 0 + solve( i+1, 0, prices));
        }
        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n,vector<int> (2,-1));
        return solve(0,1,prices);
    }
};