#pragma once


struct Item 
{
    int weight;
    int value;
};

std::ostream& operator<< (std::ostream& os, const Item& item)
{
    return os << "[value = " << item.value << ", weight = " << item.weight << "]";
}