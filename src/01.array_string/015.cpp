#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int candy(vector<int>& ratings) {
    int inc = 1;  // 递增序列长度
    int pre = 1;  // 临时存储的递增序列长度
    int dec = 0;  // 递减序列长度
    int res = 1;  // 总共的糖果数

    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] >= ratings[i - 1]) {  // 递增序列
        dec = 0;  // 现在是递增序列, 将递减序列计数器置0
        pre =
            ratings[i] == ratings[i - 1] ? 1 : pre + 1;  // 相等就不是递增序列了
        res += pre;
        inc = pre;
      }
      if (ratings[i] < ratings[i - 1]) {  // 递减序列
        dec++;
        if (inc == dec) {
          dec++;  // 如果递增序列长度和递减序列长度一样,
                  // 将递增序列的最后一个项并入递减序列
        }
        res += dec;
        pre = 1;  // 现在是递减序列, 将递增序列计数器置1
      }
    }
    return res;
  }
};

int main(int argc, char** argv) {
  vector<int> ratings = {1, 1};
  Solution s;
  cout << s.candy(ratings) << endl;

  return 0;
}