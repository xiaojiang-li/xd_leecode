/*
 * @Descripttion: 罗马数字转整数
 * @version: 1.0
 * @Author: Li Xiaodong
 * @Date: 2023-05-19 22:20:40
 * @LastEditTime: 2023-05-20 23:17:15
 */
/*
 * @Descripttion:
 * @version: 1.0
 * @Author: Li Xiaodong
 * @Date: 2023-05-19 22:20:40
 * @LastEditTime: 2023-05-20 17:30:25
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int romanToInt(string s);

 private:
  unordered_map<char, int> roman_ = {{'I', 1},   {'V', 5},   {'X', 10},
                                     {'L', 50},  {'C', 100}, {'D', 500},
                                     {'M', 1000}};
  // enum class Roman { I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
  // };
};

int Solution::romanToInt(string s) {
  int ret = 0;

  for (int i = 0; i < s.size() - 1; i++) {
    if (roman_[s[i]] < roman_[s[i + 1]]) {
      ret -= roman_[s[i]];
    } else {
      ret += roman_[s[i]];
    }
  }
  return ret + roman_[s.back()];
}

int main(int argc, char **argv) {
  // string str = "MCMXCIV";
  string str = "III";
  Solution s;
  cout << s.romanToInt(str) << endl;

  return 0;
}