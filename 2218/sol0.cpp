#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> p;
    vector<vector<int>> psum;
    vector<vector<int>> dp;
    vector<int> ilen;
    int total_n;
    int n;

    int solve(int k, int i, string space) {
        // cout << space << k << " " << i << endl;

        int ans = 0;
        if (i == n) {
            // cout << space << "END\n";
            return 0;
        }
        // cout << space << "remaining elements in stacks: " << total_n - ilen[i] << "\n";
        if (k == 0) return 0;
        if (k > total_n - ilen[i]) {
            return 0;
        }
        if (dp[k][i] != -1) return dp[k][i];
        if (k == total_n - ilen[i]) {
            int sum = 0;
            for (int it = i; it < n; it++) sum += psum[it][p[it].size()];
            return dp[k][i] = sum;
        }
        for (int it = 0; it < p[i].size(); it++) {
            // cout << space << "Picking " << it+1 << " elements form " << i << " stack with sum " << psum[i][it] << "\n";
            ans = max(ans, solve(k - it - 1, i + 1, space + "    ") + psum[i][it + 1]);
            if (k - it - 1 == 0) break;
        }
        // don't choose from this stack
        // cout << space << "DONT PICK from" << i << " stack\n";
        ans = max(ans, solve(k, i + 1, space + "    "));
        // return the solution
        return dp[k][i] = ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        p = piles;
        n = piles.size();
        dp = vector<vector<int>>(k + 1, vector<int>(n + 1, -1));
        // calculate the no of items
        ilen = vector<int>(n, 0);
        for (int i = 1; i < n; i++) {
            ilen[i] = piles[i - 1].size() + ilen[i - 1];
        }
        total_n = ilen[n - 1] + piles[n - 1].size();

        // calculate the prefix sum
        psum = vector<vector<int>>(n);
        for (int i = 0; i < n; i++) {
            psum[i] = vector<int>(p[i].size() + 1);
            for (int j = 0; j < p[i].size(); j++) {
                psum[i][j + 1] = psum[i][j] + p[i][j];
            }
        }

        // solve the answer
        return solve(k, 0, "");
    }
};