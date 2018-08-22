#include <iostream>
#include "merge_sort.h"

int main()
{
    int Size;
    std::cout<<"\nWhat is the size of array ?\n";
    std::cin>>Size;
    auto array = new int[Size];

    for (int i = 0; i < Size; ++i)
    {
        std::cout<<"\nInput the values of index "<<i<<" : "<<"\n";
        std::cin>>array[i];
    }

    merge_sort(array, 0, Size-1);

    for (int i = 0; i < Size; ++i)
        std::cout<<array[i]<<"\n";

}

//
// Created by atrivedi on 8/20/18.
//

