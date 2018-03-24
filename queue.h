//
// Created by atrivedi on 3/21/18.
//
/*****Implementing priority queue using Single linked list********/
#pragma once

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
        //insertion if queue's front's priority is less than given then creating a new front
    else if(priority < front->degree)
    {
        temp->next = front;
        front = temp;
    }
        //insertion if queue's rear's priority is less than or equal given then creating a new rear and FCFS rule
    else if(priority >= rear->degree)
    {
        rear->next = temp;
        rear = rear->next;
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
    while(temp->next->degree <= priority)
        temp = temp->next;

    return temp;
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
