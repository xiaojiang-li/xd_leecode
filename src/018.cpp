/*
 * @Descripttion: 整数转罗马数字
 * @version: 1.0
 * @Author: Li Xiaodong
 * @Date: 2023-05-19 23:01:50
 * @LastEditTime: 2023-05-20 23:17:02
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string intToRoman(int num);

 private:
  const int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  const string str[13] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                          "XL", "X",  "IX", "V",  "IV", "I"};
};

string Solution::intToRoman(int num) {
  string s;
  while (num > 0) {
    int max = 0; // 
    for (int i = max; i < 13; ++i) {
      if (num >= nums[i]) {
        num -= nums[i];
        s += str[i];
        max = i;
        break;
      }
    }
  }

  return s;
}

int main(int argc, char **argv) {
  Solution s;
  cout << s.intToRoman(13) << endl;

  return 0;
}