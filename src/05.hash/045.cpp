#include <stdio.h>

#include <set>

class Solution {
 public:
  bool isHappy(int n);
  int getNext(int n);
};

int Solution::getNext(int n) {
  int res = 0;
  while (n > 0) {
    int d = n % 10;
    n /= 10;
    res += d * d;
  }
  return res;
}

bool Solution::isHappy(int n) {
  std::set<int> set;
  while (n != 1 && !set.count(n)) {
    set.insert(n);
    n = getNext(n);
  }
  return n == 1;
}

int main(int argc, char **argv) {
  Solution sol;
  printf("%d\n", sol.isHappy(4));
  return 0;
}