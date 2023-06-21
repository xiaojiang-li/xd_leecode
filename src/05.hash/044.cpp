#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res = vector<int>(2, 0);
    map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      if (map.count(nums[i])) {
        res[0] = map[nums[i]];
        res[1] = i;
      }
      map[target - nums[i]] = i;
    }
    return res;
  }
};

int main(int argc, char** argv) {
  vector<int> nums = {3,3};
  Solution sol;
  for (const auto& m : sol.twoSum(nums, 6)) cout << m << " ";
  cout << endl;

  return 0;
}