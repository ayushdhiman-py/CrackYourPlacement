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


// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; --i) {
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            dp[i][0] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
        }

        return dp[0][1];
    }
};
