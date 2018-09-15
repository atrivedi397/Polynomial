#include <iostream>
#include <cmath>
#include "heap_sort.h"


int main()
{
    int Size;
    std::cin>>Size;

    auto array = new int[Size];
    for (int i = 0; i < Size; i++)
    {
        std::cout<<"\nAt index : "<<i<<"\n";
        std::cin>>array[i];
    }

    heapsort(array, Size);

    for (int j = 0; j < Size; j++)
        std::cout<<array[j]<<"\n";
}

//
// Created by atrivedi on 9/13/18.
//