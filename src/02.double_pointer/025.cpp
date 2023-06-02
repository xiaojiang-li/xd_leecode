#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    string sgood;
    for (const auto &m : s) {
      if (isalnum(m)) sgood += tolower(m);  // 将所有的大写全部转换为小写
    }

    int i = 0;
    int j = sgood.length() - 1;
    while (i < j) {
      if (sgood[i] == sgood[j]) {
        i++;
        j--;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char **argv) {
  string str = "A man, a plan, a canal: Panama";
  Solution s;
  cout << s.isPalindrome(str) << endl;
  return 0;
}