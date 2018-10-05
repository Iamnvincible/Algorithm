#ifndef BINARY_SEARCH
#define BINARY_SEARCH
#include <vector>
class Binary_Search
{
  public:
    int Search(std::vector<int> v, int l, int r, int key)
    {
        if (l <= r)
        {
            int m = l + (r - l) / 2;
            if (key == v[m])
            {
                return m;
            }
            else if (key < v[m])
            {
                r = m - 1;
                return Search(v, 0, r, key);
            }
            else
            {
                l = m + 1;
                return Search(v, l, r, key);
            }
        }
        else
        {
            return -1;
        }
    }
};
#endif