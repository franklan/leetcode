#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // f[k, ii] = get maxProfix until ii days with k transactions
        // f[0, ii] = 0
        // f[k, 0] = 0
        // f[k, ii] = std::max(f[k, ii-1], f[k-1, jj] + prices[ii] - prices[jj]) { jj in range of [0, ii-1] }
        //               = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
        // this is a mathematical derivation. we can get max(f[k-1, jj] - prices[jj]) in the loop
        
        if (prices.size() <= 1) return 0;
        else {
            int K = 2; // number of max transation allowed
            int maxProf = 0;
            vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
            for (int kk = 1; kk <= K; kk++) {
                int tmpMax = f[kk-1][0] - prices[0];
                for (int ii = 1; ii < prices.size(); ii++) {
                    f[kk][ii] = max(f[kk][ii-1], prices[ii] + tmpMax);
                    tmpMax = max(tmpMax, f[kk-1][ii] - prices[ii]);
                    maxProf = max(f[kk][ii], maxProf);
                }
            }
            return maxProf;
        }
    }
};
