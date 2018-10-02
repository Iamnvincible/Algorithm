#ifndef INSERTION_SORT
#define INSERTION_SORT
#include <vector>
class Insertion_Sort
{
  public:
    void Sort(std::vector<int> &v)
    {

        for (size_t i = 1; i < v.size(); i++)
        {
            int key = v[i];
            int j = i - 1;
            while (key < v[j] && j >= 0)
            {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = key;
        }
    }
};
#endif