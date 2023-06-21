#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> mmap;
    for (int i = 0; i < magazine.length(); i++) {
      mmap[magazine[i]]++;
    }
    for (int i = 0; i < ransomNote.length(); i++) {
      mmap[ransomNote[i]]--;
      if (mmap[ransomNote[i]] < 0) return false;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  string ransomNote = "a";
  string magazine = "a";
  Solution s;
  cout << s.canConstruct(ransomNote, magazine) << endl;
  return 0;
}