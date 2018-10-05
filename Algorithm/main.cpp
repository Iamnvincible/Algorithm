#include "Insertion_sort.h"
#include "Merge_sort.h"
#include "RandomArray.h"
#include "Binary_Search.h"
#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    // Insertion_Sort s;
    RandomArray r;
    // auto randomarray = r.GenerateRandomArray(1000, 100);
    // std::cout << "inertion sort" << std::endl;
    // std::cout << std::endl;
    // s.Sort(randomarray);
    int size = 100;
    if (argc > 1)
    {
        size = atoi(argv[1]);
    }
    auto randomarray2 = r.GenerateRandomArray(size, 100);
    for (size_t i = 0; i < randomarray2.size(); i++)
    {
        std::cout << randomarray2[i] << " ";
    }
    std::cout << std::endl;
    Merge_sort m;
    m.merge_sort(randomarray2, 0, randomarray2.size() - 1);
    std::cout << "std::sort" << std::endl;
    std::sort(randomarray2.begin(), randomarray2.end());
    for (size_t i = 0; i < randomarray2.size(); i++)
    {
        std::cout << randomarray2[i] << " ";
    }
    std::cout << std::endl;
    Binary_Search b;
    int index = b.Search(randomarray2, 0, randomarray2.size() - 1, 100);
    std::cout << index << std::endl;
    return 0;
}
