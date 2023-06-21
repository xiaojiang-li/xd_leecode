#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int, int> map;  // 键为数字, 键值对应数字在数组中的位置
    for (int i = 0; i < nums.size(); i++) {
      if (map.count(nums[i]) && i - map[nums[i]] <= k) {
        return true;
      }

      map[nums[i]] = i;
    }
    return false;
  }
};

int main(int argc, char** argv) {
  vector<int> nums = {1, 2, 3, 1, 2, 3};
  Solution sol;
  cout << sol.containsNearbyDuplicate(nums, 2) << endl;

  return 0;
}