class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (auto& account : accounts) {
            int wealth = 0;
            for (int money : account) {
                wealth += money;
            }
            maxWealth = max(maxWealth, wealth);
        }
        return maxWealth;
    }
};