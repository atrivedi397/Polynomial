#include <iostream>
#include "radix_sort.h"

int main()
{
    int Size = -1;
    std::cout<<"\nHow many elements do you want to sort ?\n";
    std::cin>>Size;

    auto array = new int[Size];
    for(int i = 0; i < Size; i++)
    {
        std::cout<<"\nProvide the number at index "<<i<<"\n";
        std::cin>>array[i];
    }

    RadixSort object;

    object.radixSort(array, Size);

    delete[] array;
}

//
// Created by atrivedi on 9/25/18.
//

