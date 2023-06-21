#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> ranges;
    int i = 0;
    int n = nums.size();
    while (i < n) {
      int low = i;
      i++;
      while (i < n && nums[i] == nums[i - 1] + 1) i++;

      int high = i - 1;
      string tmp = to_string(nums[low]);
      if (low < high) {
        tmp.append("->");
        tmp.append(to_string(nums[high]));
      }
      ranges.push_back(std::move(tmp));
    }
    return ranges;
  }
};

int main(int argc, char **argv) {
  vector<int> nums = {0, 1, 2, 4, 5, 7};
  Solution sol;
  for (const auto &m : sol.summaryRanges(nums)) cout << m << endl;

  return 0;
}