#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) { return Fun1(nums); }

  vector<int> Fun1(vector<int>& nums);
};

vector<int> Solution::Fun1(vector<int>& nums) {
  int n = nums.size();
  vector<int> r(n, 1);
  for (int i = n - 2; i >= 0; --i) {
    r[i] = r[i + 1] * nums[i+1];
  }
  vector<int> l(n, 1);
  for (int i = 1; i < n; ++i) {
    l[i] = l[i - 1] * nums[i-1];
  }
  // for (int i = 0; i < n; ++i) {
  //   cout << r[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < n; ++i) {
  //   cout << l[i] << " ";
  // }
  // cout << endl;
  vector<int> ret(n,1);
  for (int i = 0; i < n; ++i) {
    ret[i] = l[i] * r[i];
  }
  return ret;
}

int main(int argc, char** argv) {
  vector<int> nums = {1, 2, 3, 4};
  Solution s;
  vector<int> ret = s.productExceptSelf(nums);
  for (const auto &m : ret) {
    cout << m << " ";
  }
  return 0;
}