/*
 * @Descripttion:
 * @version: 1.0
 * @Author: Li Xiaodong
 * @Date: 2023-05-21 00:13:51
 * @LastEditTime: 2023-05-21 00:42:19
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    string ret = "";
    int m = 2 * numRows - 2;
    int n = s.length();
    if (numRows == 1 || numRows >= n) return s;
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j + i < n; j += m) {
        ret += s[j + i];
        if (i != 0 && i != numRows - 1 && j + m - i < n) ret += s[j + m - i];
      }
    }
    return ret;
  }
};

int main(int argc, char **argv) {
  string str = "PAYPALISHIRING";
  Solution s;
  cout << s.convert(str, 4) << endl;
  return 0;
}
