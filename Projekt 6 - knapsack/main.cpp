#include <iostream>
#include <vector>
#include <array>
#include <bitset>

#include "Item.h"
#include "bitIndex.h"

#define PROGRESS

constexpr int size = 32;
constexpr int weightMax = 75;

std::pair<bitIndex, int> bruteforce(const std::array<Item, size>& items)
{
    std::cout << "start of calculation...\n";

    std::pair<bitIndex, int> best;
    best.second = -1;

    bitIndex bi;
    do
    {
#ifdef PROGRESS
        if (bi % 100'000'000 == 0)
            std::cout << " left: " << (bitIndex::MAX_INDEX - bi) << '\n';
#endif
        int value = 0;
        int weight = 0;
        for (int i = 0; i < size; ++i)
        {
            if (!bi[i])
                continue;

            if ((weight + items[i].weight) > weightMax)
                break;

            weight += items[i].weight;
            value += items[i].value;
        }

        if (best.second < value)
            best = {bi, value};
        

    } while (bi++ < bitIndex::MAX_INDEX);

    return best;
}


int main()
{
    std::array<Item, size> items = { {
        { 3, 7 }, { 1, 4 }, { 6, 9 }, { 10, 18 },
        { 1, 9 }, { 4, 15 }, { 9, 4 }, { 1, 2 },
        { 7, 6 }, { 2, 13 }, { 6, 18 }, { 1, 12 },
        { 6, 12 }, { 2, 16 }, { 2, 19 }, { 4, 19 },
        { 8, 10 }, { 1, 16 }, { 7, 14 }, { 3, 3 },
        { 6, 14 }, { 2, 4 }, { 9, 15 }, { 5, 7 },
        { 3, 5 }, { 3, 10 }, { 4, 10 }, { 7, 13 },
        { 3, 19 }, { 5, 9 }, { 30, 8 }, { 50, 5 }
     } };

    auto[index, value] = bruteforce(items);

    std::cout << "> indices of elems used: " << std::bitset<32>(index) << '\n'
              << "> value sum = " << value << '\n';

    std::cin.get();
}