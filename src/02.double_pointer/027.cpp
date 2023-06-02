#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    return Fun1(numbers, target);
  }

 private:
  // 双指针
  vector<int> Fun1(vector<int>& numbers, int target);
  // 二分法+双指针
  vector<int> Fun2(vector<int>& numbers, int target);
};

vector<int> Solution::Fun1(vector<int>& numbers, int target) {
  int n = numbers.size();
  int i = 0;
  int j = n - 1;
  while (i < j) {
    if (numbers[i] + numbers[j] > target) {
      j--;
    } else if (numbers[i] + numbers[j] < target) {
      i++;
    } else {
      return {i + 1, j + 1};
    }
  }

  return {-1, -1};
}

vector<int> Solution::Fun2(vector<int>& numbers, int target) {
  return {-1, -1};
}

int main(int argc, char** argv) {
  vector<int> numbers = {2, 7, 11, 15};
  Solution s;
  for (const auto& m : s.twoSum(numbers, 9)) cout << m << " ";
  cout << endl;

  return 0;
}