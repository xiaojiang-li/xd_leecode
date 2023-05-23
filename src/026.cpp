#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    // int i = s.length();
    // int j = t.length();
    int i = 0;
    for (int j = 0; j <= t.length(); j++) {
      if (i == s.length()) return true;
      if (i != s.length() && j == t.length()) return false;
      if (s[i] == t[j]) {
        i++;
        continue;
      }
    }
    return false;
  }
};

int main(int argc, char **argv) {
  string s = "", t = "";
  Solution sol;
  cout << sol.isSubsequence(s, t) << endl;
  return 0;
}