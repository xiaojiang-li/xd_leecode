#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) { return Fun1(citations); }

  int Fun1(vector<int>& citations);
};

int Solution::Fun1(vector<int>& citations) {
  int n = citations.size();
  vector<int> arr = vector<int>(n + 2, 0);
  for (int i = 0; i < n; ++i) {
    if (citations[i] > n) {
      arr[n]++;
    } else {
      arr[citations[i]]++;
    }
  }
  // for (const auto& m : arr) {
  //   cout << m << "";
  // }
  for (int i = n; i >= 0; i--) {
    arr[i] += arr[i + 1];
    if (arr[i] >= i) return i;
  }
  return 0;
}

// google规范中, 指针变量声明时, *前置与后置都可以
int main(int argc, char** argv) {
  vector<int> citations = {3, 0, 6, 1, 5};
  Solution s;
  cout << endl << s.hIndex(citations) << endl;
  return 0;
}