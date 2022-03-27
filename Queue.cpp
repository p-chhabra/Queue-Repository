#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    public:
    int nextIndex;
    int firstIndex;
    T * arr;
    int size;
    int capacity;

    Queue()
    {
        capacity = 5;
        arr = new T[capacity];
        nextIndex = 0;
        firstIndex = 0;
        size = 0;
    }

    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new T[capacity];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size==0;
    }

    T front()
    {
       if(size == 0){
        cout<<"Queue empty"<<endl;
        return 0;
       }
       return arr[firstIndex];
    }

    ///Insert element
    void push(T ele)
    {
        if(size == capacity){
            cout<<"Queue Full"<<endl;
            return;
        }
        arr[nextIndex] = ele;
        nextIndex = (nextIndex + 1)%capacity;
        if(firstIndex == -1) firstIndex = 0;
        size++;

        ///optional
        if(size==0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
    }

    void pop()
    {
        if(isEmpty()){
            cout<<"Empty Queue"<<endl;
            return;
        }
        firstIndex = (firstIndex + 1)%capacity;
        size--;
    }
};

int main()
{
    Queue<int> q1(5);
    q1.push(5);
    q1.push(2);
    q1.push(6);

    for(int i = 3; i<2000; i = i*3)
    {
        q1.push(i);
    }
    cout<<q1.front()<<endl;

    cout<<endl<<"Size of Queue: "<<q1.getSize()<<endl;
    q1.pop();
    q1.pop();
    cout<<endl;
    cout<<q1.front()<<endl;
    cout<<endl<<"Size of Queue: "<<q1.getSize()<<endl<<endl;
    cout<<"Front Element:"<<q1.front()<<endl;


    return 0;
}