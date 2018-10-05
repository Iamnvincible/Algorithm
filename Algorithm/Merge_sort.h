#ifndef MERGE_SORT
#define MERGE_SORT
#include <vector>
class Merge_sort
{
  public:
    void merge_sort(std::vector<int> &v, int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;
            merge_sort(v, l, m);
            merge_sort(v, m + 1, r);
            Merge(v, l, m, r);
        }
    }
    void Merge(std::vector<int> &v, int l, int m, int r)
    {
        std::vector<int> temp(r - l + 1);
        int i = l, j = m + 1, k = 0;
        while (i <= m && j <= r)
        {
            if (v[i] < v[j])
            {
                temp[k++] = v[i++];
            }
            else
            {
                temp[k++] = v[j++];
            }
        }
        while (i <= m)
        {
            temp[k++] = v[i++];
        }
        while (j <= r)
        {
            temp[k++] = v[j++];
        }
        k--;
        while (k >= 0)
        {
            v[r--] = temp[k--];
        }
    }
};
#endif