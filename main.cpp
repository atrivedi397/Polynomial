#include<iostream>
#include "queue.h"

class operations : public objects
{
public:
    void add_polynomial(objects* ob_1, objects* ob_2);
};

void operations::add_polynomial(objects* ob_1, objects* ob_2)
{
    objects* ob_3;
    node* front1;
    node* front2;
    node* rear1;
    node* rear2;
    ob_3 = new objects;
    front1 = ob_1->get_front_rear(1);
    front2 = ob_2->get_front_rear(1);
    rear2 = ob_2->get_front_rear(2);
    rear1 = ob_1->get_front_rear(2);

    while(front1 != nullptr && front2 != nullptr)
    {
        if(front1->degree == front2->degree)
        {
            ob_3->create_node((front1->coefficient + front2->coefficient) , front1->degree);
            front1 = front1->next;
            front2 = front2->next;
        }
        else if(front1->degree > front2->degree)
        {
            ob_3->create_node(front2->coefficient , front2->degree);
            front2 = front2->next;
        }
        else
        {
            ob_3->create_node(front1->coefficient , front1->degree);
            front1 = front1->next;
        }
    }

    if(rear1->degree >= rear2->degree)
    {
        while(front1 != nullptr)
        {
            ob_3->create_node(front1->coefficient , front1->degree);
            front1 = front1->next;
        }
    }

    if(rear1->degree <= rear2->degree)
    {
        while(front2 != nullptr)
        {
            ob_3->create_node(front2->coefficient , front2->degree);
            front2 = front2->next;
        }
    }

    ob_3->display();
}

int main()
{
    objects* ob1;
    ob1 = new objects;
    ob1->create_node(77 , 7);
    ob1->create_node(65 , 1);
    ob1->create_node(36 , 2);
    ob1->create_node(98 , 4);
    ob1->display();
    std::cout<<std::endl<<std::endl;

    objects* ob2;
    ob2 = new objects;
    ob2->create_node(15 , 4);
    ob2->create_node(10 , 2);
    ob2->create_node(12 , 3);
    ob2->create_node(-15 , 1);
    ob2->display();


    operations* to_be_added;

    to_be_added = new operations;
    to_be_added->add_polynomial(ob1 , ob2);

    return 0;
}

//
// Created by atrivedi on 3/21/18.
//

