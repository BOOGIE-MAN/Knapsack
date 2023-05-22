#pragma once
#include <iostream>


struct bitIndex
{
    uint32_t indicies = 0;
    static constexpr uint32_t MAX_INDEX = UINT32_MAX;

    bool operator[](size_t) const;

    bitIndex operator++(int);

    operator uint32_t() const
    {
        return indicies;
    }
};

