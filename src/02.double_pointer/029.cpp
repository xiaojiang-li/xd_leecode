#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums);
};

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
  // sort
  sort(nums.begin(), nums.end(), [](int i, int j) { return i < j; });
  int n = nums.size();
  vector<vector<int>> ret;
  for (int i = 0; i <= n - 3; ++i) {
    int j = i + 1;
    int k = n - 1;
    if (i > 0 && nums[i] == nums[i - 1]) continue;
    while (j < k) {
      if (nums[i] + nums[j] + nums[k] == 0) {
        vector<int> tmp = {nums[i], nums[j], nums[k]};
        ret.emplace_back(tmp);
        j++;
        k--;
        while (j < k && nums[j] == nums[j - 1]) j++;
      } else if (nums[i] + nums[j] + nums[k] > 0) {
        k--;
      } else {
        j++;
      }
    }
  }
  return ret;
};

int main(int argc, char** argv) {
  // vector<int> nums = {-1, 0, 1, 2, -1, -4};
  // vector<int> nums = {-1, -1, -1, -1, 0, 1};
  // vector<int> nums = {-1, 0, 0, 0, 0, 1};
  // vector<int> nums = {-2, 0, 0, 2, 2};
  vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};

  Solution s;
  for (const auto& v : s.threeSum(nums)) {
    for (const auto& m : v) cout << m << " ";
    cout << endl;
  }
  return 0;
}