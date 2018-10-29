// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include "Binary_Search.h"
// #include "Insertion_sort.h"
// #include "Merge_sort.h"
// #include "RandomArray.h"

#include "Huffman.hpp"
int main(int argc, char const *argv[]) {
  Huffman h;
  std::string s = "aabbcccddd";
  auto r = h.huffman(s);
  for (auto i : r) {
    std::cout << i.first << ":" << i.second << std::endl;
  }
}
