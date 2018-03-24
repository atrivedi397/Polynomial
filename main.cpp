#include<iostream>
#include "queue.h"
using namespace std;

objects* ob1; objects* ob2; operations* to_be_added;
int degree, coefficient, ans;

//function for taking input
objects* input(objects* instance , int a);

int main()
{
    ob1 = new objects;
    ob2 = new objects;
    std::cout<<"\nThis is a program for adding/subtracting two polynomials.\n\n";
    ob1 = input(ob1,1);
    ob2 = input(ob2,2);
    cout<<endl;
    ob1->display();
    cout<<endl;
    ob2->display();
    to_be_added = new operations;
    to_be_added->add_polynomial(ob1 , ob2);

    return 0;
}

//function input definition
objects* input(objects* instance, int a)
{
    bool flag;
    do
    {
        std::cout<<"\nEnter your coefficient and degree one by one for "<<a<<" equation .\n";
        std::cin>>coefficient>>degree;
        instance->create_node(coefficient , degree);

        std::cout<<"\n\nWant to enter more?\n1.Yes\n2.No(Press any key)\n\n";
        std::cin>>ans;
        flag = ans == 1;
    }while(flag);

    return instance;
}
//
// Created by atrivedi on 3/21/18.
//

