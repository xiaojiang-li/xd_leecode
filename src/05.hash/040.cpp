#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> smap;
    unordered_map<char, char> tmap;

    int len = s.length();
    for (int i = 0; i < len; i++) {
      char x = s[i];
      char y = t[i];

      if ((smap.count(x) && smap[x] != y) || (tmap.count(y) && tmap[y] != x)) {
        return false;
      }
      smap[x] = y;
      tmap[y] = x;
    }
    return true;
  }
};


int main(int argc, char **argv) {
  string s = "sss";
  string t = "tta";
  Solution sol;

  cout << sol.isIsomorphic(s,t) << endl;

  return 0;
}