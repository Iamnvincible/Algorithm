#ifndef HUFFMAN
#define HUFFMAN
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
typedef struct node {
  char ch;  //存储该节点表示的字符，只有叶子节点用的到
  int val;  //记录该节点的权值
  struct node *self, *left,
      *right;  //三个指针，分别用于记录自己的地址，左孩子的地址和右孩子的地址
  friend bool operator<(const node &a,
                        const node &b)  //运算符重载，定义优先队列的比较结构
  {
    return a.val > b.val;  //这里是权值小的优先出队列
  }
} node;
class Huffman {
  //输入字符串，输出每个字符串的编码
 public:
  std::priority_queue<node> p;
  std::unordered_map<char, std::string> code;
  std::unordered_map<char, std::string> huffman(std::string str) {
    // int a;a是0？是标准还是编译器确定的？
    //统计
    std::unordered_map<char, int> character;
    for (size_t i = 0; i < str.length(); i++) {
      auto s = character.find(str[i]);
      if (s != character.end()) {
        character[str[i]]++;
      } else {
        character[str[i]] = 1;
      }
    }
    //入队
    for (auto i = character.begin(); i != character.end(); i++) {
      node *root = (node *)malloc(sizeof(node));
      root->val = i->second;
      root->ch = i->first;
      root->self = root;
      root->left = root->right = NULL;
      p.push(*root);
    }
    //按优先级合并
    while (p.size() > 1) {
      auto first = p.top();
      p.pop();
      auto second = p.top();
      p.pop();
      node *root = (node *)malloc(sizeof(node));
      root->val = first.val + second.val;
      root->left = first.self;
      root->right = second.self;
      root->self = root;
      p.push(*root);
    }
    auto root = p.top();
    p.pop();
    viewtree(root.self, "");
    // for (auto i = code.begin(); i != code.end(); i++) {
    //   char x = i->first;
    //   std::cout << x << std::endl;
    //   // std::cout << i->first << ":" << i->second << std::endl;
    // }
    return code;
  }

  //  private:

  void viewtree(node *root, std::string former_code) {
    if (root->left == root->right) {
      if (former_code == "") {
        code[root->ch] = "0";
      } else {
        code[root->ch] = former_code;
      }
    } else {
      auto left = former_code + "0";
      viewtree(root->left, left);
      auto right = former_code + "1";
      viewtree(root->right, right);
    }
  }
};
#endif