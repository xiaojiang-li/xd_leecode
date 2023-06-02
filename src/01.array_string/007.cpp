#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) { return Fun2(prices); }
  // 两种解法
  // 暴力求解: 两两比较, 这里不写了
  int Fun1(vector<int>& prices);
  // 动态规划
  int Fun2(vector<int>& prices);
};

int max(int i, int j) { return i > j ? i : j; };

int min(int i, int j) { return i < j ? i : j; }

int Solution::Fun2(vector<int>& prices) {
  int max_profit = 0;  // 股票获利最多的价格
  int min_n = prices[0];       // 股票最便宜的价格
  for (const auto& m : prices) {
    min_n = min(min_n, m);
    int today_profit = m - min_n;  // 股票今天获利最多的价格
    max_profit = max(today_profit, max_profit);
  }
  return max_profit;
}

int main(int argc, char** argv) {
  vector<int> prices = {2, 1, 2, 1, 0, 1, 2};
  Solution s;
  cout << s.maxProfit(prices) << endl;
  return 0;
}