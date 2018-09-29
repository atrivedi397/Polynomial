#pragma once
#include <iostream>
using namespace std;

// Create an array of size 10
// Get the digits in the max number of it
// start from least significant bit
// then go to next significant bit
// and so on

// function to find the maximum in a given list
template <typename type>
int find_max_in(const type* list, int ListSize)
{
    int largest = list[0];
    for (int i = 1; i < ListSize ; i++)
    {
        if(largest < list[i])
            largest = list[i];
    }
    return largest;
};


// function to find the number of digits in a given number
short getDigitsInNumber(int number)
{
    if(number == 0)  //the number will be of at least one digit number then return 1
        return 1;

    short countDigits = 0;   //else count the digits by dividing by 10
    while(number > 0)
    {
        number /= 10;
        countDigits += 1;
    }
    return countDigits;
};


// function for getting a significant digit at a particular place
int get_Significant_Digit(int number, int place)
{
    int totalDigits = getDigitsInNumber(number);
    try
    {
        if(place < 1)
            throw place;
    }
    catch (short non_existing_place)
    {
        std::cout << "function called for obtaining non existing significant digit" << std::endl;
        exit(1);
    }
    if(place > totalDigits)  // place can never exceed the total number of digits, hence exit
        return 0;
    else
    {
        short count = 1;
        while (count < place)
        {
            number /= 10;
            count++;
        }
        number %= 10;
    }
    return number;
};

///********** Class for the Radix Sort ***************///
class RadixSort
{
    int radix;             //base of the number system
    int* unsortedList;     //taking to make a copy of the list passed
    int unsortedListSize;  //size of the input list
    int* sortedList;       //the final sorted list
    struct SLL             //structure for the linked list by which the numbers are to be placed at a position
    {
        int element {0};
        SLL* next{nullptr};
    };

public:
    explicit RadixSort(int Radix =10):
        radix(Radix), unsortedList(nullptr), unsortedListSize(0), sortedList(nullptr){}

    SLL** start = new SLL* [radix];  //creating the boxes of linked list
    SLL** end = new SLL* [radix];    //hence starts and ends for linked list

    //placing the element at a particular position
    //(appending to a linked list according to the significant digit)
    //according to a significant digit of the number at a place
    void arrangeElements(int* list, int at_place)
    {
        int digitAtIndex;
        for (int i = 0; i < unsortedListSize; i++)
        {
            digitAtIndex = get_Significant_Digit(list[i], at_place);  //getting significant digit at a place
            auto newListElement = new SLL;
            newListElement->element = list[i];

            if(start[digitAtIndex] == nullptr) //if a start pointer is null at a particular place then making it start and end
            {
                start[digitAtIndex] = newListElement;
                end[digitAtIndex] = newListElement;
            }
            else                 //else appending that element to a particular end position where already a linked list exists
            {
                end[digitAtIndex]->next = newListElement;
                end[digitAtIndex] = end[digitAtIndex]->next;
            }
        }
    }

    // Printing a list
    void printList(int* const list)
    {
        int j = 0, i = 0;
        for (i = 0; j < unsortedListSize;)
        {
            auto tempStart = start[i];
            if(tempStart == nullptr)
                i++;
            else
            {
                while(tempStart != nullptr)
                {
                    list[j] = tempStart->element;
                    tempStart = tempStart->next;
                    j += 1;
                }
                i++;
            }
        }

        //printing intermediate sorts
        for(int k = 0; k < unsortedListSize; k++)
            std::cout<<unsortedList[k]<<" ";
        std::cout<<std::endl;

        //freeing the previous occupied start and end pointers and making them null
        //so that we can insert elements in a new way again(and hence not adding to previously existed elements)
        //to sort for the next step
        delete[] start;
        delete[] end;
        for (int k = 0; k < radix; ++k)
        {
            start[k] = nullptr;
            end[k] = nullptr;
        }
    }

    //Actual Radix Sort Logic
    void radixSort(int* const list, int ListSize)
    {
        unsortedList = list;
        unsortedListSize = ListSize;
        int greatest = find_max_in(list, ListSize);
        int maxDigits = getDigitsInNumber(greatest);
        for(int place = 1; place <= maxDigits; place++)
        {
            arrangeElements(unsortedList, place);
            printList(unsortedList);
        }
    }

    ~RadixSort()
    {
        delete[] start;
        delete[] end;
    }
};



//
// Created by atrivedi on 9/25/18.
//

