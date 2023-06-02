#include <assert.h>

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
};

// 如果从x出发能到y但是不能到y+1, 那么[x, y]中所有的加油站都不能到y+1
int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  assert(gas.size() == cost.size());

  int n = gas.size();
  int i = 0;  // 从第几个加油站开始

  while (i < n) {
    int sum_gas = 0;
    int sum_cost = 0;
    int cnt = 0;  // 本次循环, 汽车经过了多少个加油站

    while (cnt < n) {
      int j = (i + cnt) % n;  // 目前到哪一个加油站了
      sum_gas += gas[j];
      sum_cost += cost[j];
      if (sum_cost > sum_gas) break;
      cnt++;
    }
    if (cnt == n) {
      return i;
    } else {
      i = i + cnt + 1; // i如果大于n了, 证明所有出发点都不行
    }
  }
  return -1;
}

int main (int argc, char** argv) {
  vector<int> gas = {1,2,3,4,5};    
  vector<int> cost = {3,4,5,1,2};
  Solution s;
  cout << s.canCompleteCircuit(gas, cost) << endl;

  return 0;
}