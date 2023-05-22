#include <bitset>

#include "bitIndex.h"


bool bitIndex::operator[](size_t i) const
{
    return (indicies >> i) & 1;
}

bitIndex bitIndex::operator++(int dummy)
{
    auto copy = *this;
    indicies++;
    return copy;
}

//std::ostream& operator<< (std::ostream& os, const bitIndex& bi)
//{
//    return os << std::bitset<32>(bi.indicies);
//}
