#include <iostream>
#include <vector>
#include <array>
#include <bitset>

#include "Item.h"
#include "bitIndex.h"


constexpr int size = 32;
constexpr int weightMax = 75;

std::pair<bitIndex, int> bruteforce(const std::array<Item, size>& items)
{
    std::cout << "poczatek obliczen...\n";
    //std::bitset<32> b;
    // std::cout << (int)_UI8_MAX << std::endl;

    /*for (; n <= _UI8_MAX; ++n)
        std::cout << (int)n << std::endl;*/

    std::pair<bitIndex, int> best;
    best.second = -1;

    bitIndex bi;
    do
    {
        /*b = bi.indicies;
        std::cout << bi << " = " << b << '\n';*/

#ifdef PROGRESS
        if (bi % 100'000'000 == 0)
            std::cout << " pozostalo: " << (bitIndex::MAX_INDEX - bi) << '\n';
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

    //n++;
    //std::cout << (int)n << std::endl;
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

    /*for (auto i : items)
        std::cout << i << std::endl;*/

    auto[index, value] = bruteforce(items);

    std::cout << "> index elementow: " << std::bitset<32>(index) << '\n'
              << "> suma wartosci = " << value << '\n';

    std::cin.get();
}