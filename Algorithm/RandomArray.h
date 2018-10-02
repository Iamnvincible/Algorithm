#ifndef RANDOMARRAY
#define RANDOMARRAY
#include <vector>
#include <random>
class RandomArray
{
  public:
    std::vector<int> GenerateRandomArray(size_t size, int range)
    {
        std::random_device d;
        std::default_random_engine e(d());
        std::uniform_int_distribution<unsigned> u(0, range);
        std::vector<int> res(size);

        for (size_t i = 0; i < size; i++)
        {
            res[i] = u(e);
        }
        return res;
    }
};
#endif