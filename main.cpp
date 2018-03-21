#include<iostream>
#include "queue.h"

int main()
{
    objects* ob1;
    ob1 = new objects;
    ob1->create_node(45 , 1);
    ob1->create_node(65 , 2);
    ob1->create_node(36 , 3);
    ob1->create_node(98 , 5);
    ob1->create_node(100 , 5);
    ob1->display();

    return 0;
}



//
// Created by atrivedi on 3/21/18.
//

