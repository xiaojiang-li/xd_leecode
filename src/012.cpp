#include <stdlib.h>

#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
 public:
  RandomizedSet() {
    srand(time(NULL));  // 重置随机数种子
  }

  bool insert(int val) {
    if (indices.count(val)) {  // val已经在集合中了
      return false;
    }
    int index = nums.size();
    nums.push_back(val);
    indices[val] = index;  // 使用原数组长度与插入值作为键值对；
    return true;
  }

  bool remove(int val) {
    if (!indices.count(val)) {
      return false;
    }
    int index = indices[val];  // 找到该数对应的键, 这个键就是该数在数组中的下标
    int last = nums.back();  // 找到数组的最后一个数, 把这个数赋到待删除的数上.
    nums[index] = last;
    indices[last] = index;
    nums.pop_back();
    indices.erase(val);
    return true;
  }

  int getRandom() {
    int rand_index = rand() % nums.size();
    return nums[rand_index];
  }

 private:
  vector<int> nums;
  unordered_map<int, int> indices;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */