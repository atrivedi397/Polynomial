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

    std::cout<<"\n\nYour equation is as follows:\n\n";
    while(ptr != nullptr)
    {
        std::cout<<ptr->coefficient<<"x^"<<ptr->degree<<"+ ";
        ptr =  ptr->next;
    }
    std::cout<<"= 0\n\n";
}

//subclass created for adding add/subtract method
class operations : public objects
{
public:
    void add_polynomial(objects* ob_1, objects* ob_2);
};

void operations::add_polynomial(objects* ob_1, objects* ob_2)
{
    objects* ob_3; //in which resultant is stored
    node* front1;  //for traversal along first equation
    node* front2;  //for traversal along second equation
    node* rear1;   //last of first equation
    node* rear2;   //last of second equation
    ob_3 = new objects;
    front1 = ob_1->get_front_rear(1);
    front2 = ob_2->get_front_rear(1);
    rear2 = ob_2->get_front_rear(2);
    rear1 = ob_1->get_front_rear(2);

    //definition for adding these polynomials
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

    //displaying the resultant
    ob_3->display();
}
