#include <iostream>
using namespace std;

class Queue
{
    private:
        int head;
        int back;
        int a[5];

    public:
        Queue()
        {
            head = -1;
            back = -1;

            for(int i = 0; i < 5; i++)
            {
                a[i] = 0;
            }
        }

        bool isEmpty()
        {
            if(head == -1 && back == -1)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }

        bool isFull()
        {
            if(back == 4)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        void enqueue(int value)
        {
            if(isFull())
            {
                cout << "Queue Full." << endl;
            }
            else if(isEmpty())
            {
                head = 0;
                back = 0;
                a[back] = value;
            }
            else 
            {
                back++;
                a[back] = value;
            }
        }

        int dequeue()
        {
            int temp;

            if(isEmpty())
            {
                cout << "Queue Empty." << endl;
                return 0;
            }
            else if(head == back)
            {
                temp = a[head];
                head = -1;
                back = -1;
                a[head] = 0;
                return temp;
            }
            else 
            {
                temp = a[head];
                a[head] = 0;
                head++;
                return temp;
            }
        }

        int count()
        {
            return (back + 1);
        }
        void peek(int position)
        {
            if(isEmpty())
            {
                cout << "Queue is Empty" << "\n";
            }
            else
            {
                cout << a[position];
            }
        }
        void change(int position, int value)
        {
            if(isEmpty())
            {
                cout << "Nothing to change" << "\n";
            }
            else
            {
                a[position] = value;
            }
        }
        void display()
        {
            if(isEmpty())
            {
                cout << "Queue is Empty." << "\n";
            }
            else
            {
                for(int i = back; i >= 0; i--)
                {
                    cout << a[i] << "\t";
                }
            }
        }
};
int main()
{
    Queue s1;

    s1.enqueue(50);
    s1.enqueue(10);
    s1.enqueue(20);
    s1.enqueue(1);
    s1.enqueue(2);
    
    s1.change(1, 30);
    
    s1.display();
    return 0;
}