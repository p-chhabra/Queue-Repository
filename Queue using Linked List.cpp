#include <iostream>
using namespace std;

///QUEUE IMPLEMENTATION USING LINKED LIST

//Linked List
template <typename T>
class Node
{
    public:
    T data;
    Node * next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};


//Queue Implementation
template <typename T>
class Queue
{
public:
    Node<T> * head;
    Node<T> * tail;
    int size;

    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push(T data)
    {
        if(!head)
        {
            Node<T> * n = new Node<T>(data);
            head = n;
            tail = n;
             size++;
            return;
        }

        Node<T> * n = new Node<T>(data);
        n->data = data;
        tail->next = n;
        tail = n;
        size++;
    }

    int front()
    {
        return head->data;
    }

    void pop()
    {
        if(!head)
        {
            cout<<"Queue Empty! Nothing to be deleted"<<endl;
            size--;
            return;
        }
        Node<T> * temp = head;
        delete temp;
        head = head->next;
        size--;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size==0;
    }
};

int main()
{
    Queue<int> q1;
    q1.push(2);
    q1.push(9);
    q1.push(7);
    q1.push(8);
    q1.push(5);
    q1.push(3);

    cout<<q1.front()<<endl;
    q1.pop();
    q1.pop();
    cout<<q1.front()<<endl;

    return 0;
}
