#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) { return Fun1(nums); }

  bool Fun1(vector<int>& nums);
};

int max(int i, int j) { return i > j ? i : j; }

bool Solution::Fun1(vector<int>& nums) {
  int max_n = 1;
  for (int i = 0; i < nums.size()-1; ++i) {
    max_n = max(max_n - 1, nums[i]);
    if (max_n == 0) return false;
  }
  return max_n > 0;
}

int main(int argc, char const* argv[]) {
  // vector<int> nums = {4, 3, 2, 1, 0, 5};
  vector<int> nums = {0};

  Solution s;
  cout << s.canJump(nums) << endl;
  return 0;
}