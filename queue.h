//
// Created by atrivedi on 3/21/18.
//
/*****Implementing priority queue using Single linked list********/
#pragma once


#ifndef ILLOGICALS_QUEUE_H
#define ILLOGICALS_QUEUE_H


struct node
{
    int coefficient;
    int degree;    //priority
    node* next;
};

class objects
{
private:
    node* front = nullptr;
    node* rear = nullptr;

public:
    void create_node(int coeff, int priority);
    node* delete_node();
    node* get_front_rear(int a);
    node* traversal(int priority);
    void display();
};

void objects::create_node(int coeff, int priority)
{
    node* temp; node* traversed;    //traversed is used for position where it has to be inserted according to priority
    temp = new node;
    temp->coefficient = coeff;
    temp->degree = priority;
    temp->next = nullptr;

    //insertion if queue is blank
    if(front == nullptr)
    {
        front = temp;
        rear = temp;
    }
        //insertion if queue's rear's priority is more than given
    else if(priority >= rear->degree)
    {
        rear->next = temp;
        rear = temp;
    }

        //inserting according to the priority
    else
    {
        traversed = traversal(priority);
        temp->next = traversed->next;
        traversed->next = temp;
    }
}

node* objects:: get_front_rear(int a)
{
    return a == 1 ? front : rear;
}

node *objects::delete_node()
{
    node* temp;
    temp = get_front_rear(1);

    front = temp->next;
    delete temp;

    return front;
}

node *objects::traversal(int priority)
{
    node* temp = get_front_rear(1);
    while(priority >= temp->degree)
    {
        temp = temp->next;
        return temp->next;
    }
}

void objects::display()
{
    node* ptr = get_front_rear(1);

    std::cout<<"\n\nYour given queue is as follows (priority is in brackets):\n\n";
    while(ptr != nullptr)
    {
        std::cout<<ptr->coefficient<<"("<<ptr->degree<<")->";
        ptr =  ptr->next;
    }
}

#endif //ILLOGICALS_QUEUE_H
