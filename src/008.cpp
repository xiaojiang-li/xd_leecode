#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) { return Fun1(prices); }

  // 多种算法
  // 1 动态规划
  int Fun1(vector<int>& prices);
};

int max(int i, int j) { return i > j ? i : j; }

int Solution::Fun1(vector<int>& prices) {
  const int n = prices.size();
  int f[2][2] = {0, 0, 0, 0};
  f[0][0] = 0;
  f[0][1] = -prices[0];
  for (int i = 1; i < n; ++i) { // 第一天的情况前面已经列出来了, 所以i从1开始计数
    f[1][0] = max(f[0][0], f[0][1] + prices[i]);
    f[1][1] = max(f[0][1], f[0][0] - prices[i]);
    f[0][0] = f[1][0];
    f[0][1] = f[1][1];
  }
  return f[0][0];
}

int main(int argc, char** argv) {
  vector<int> prices{7, 1, 5, 3, 6, 4};
  Solution s;
  cout << s.maxProfit(prices) << endl;
  return 0;
}