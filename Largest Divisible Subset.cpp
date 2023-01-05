class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n+1,1);
        sort(nums.begin(),nums.end());
        
        int mx = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && 1+dp[j] > dp[i]) {
                    dp[i] = 1+dp[j];
                    mx = max (mx,dp[i]);
                }
            }
        }

        vector <int> ans;
        int tmp = -1;
        for (int i = nums.size()-1; i >=0;i--) {
            if (dp[i] == mx && (tmp % nums[i] == 0 || tmp == -1)) {
                ans.push_back(nums[i]);
                mx -=1;
                tmp = nums[i];
            }
        }

        return ans;
    }
};
