#include <iostream>
#include <vector>
using namespace std;

class CircularQueue
{
private:
    int n, size;
    int head, tail;
    vector<int> queue;

public:
    CircularQueue(int n) : n(n), head(0), tail(0), size(0), queue(n) {}

    void enqueue(int val)
    {
        if (size == n)
        {
            throw runtime_error("Error: Queue Overflow\n");
        }

        queue[tail] = val;
        size++;
        tail = (tail + 1) % n;

        return;
    }

    void dequeue()
    {
        if (!size)
        {
            throw runtime_error("Error: Queue Underflow\n");
        }

        head = (head + 1) % n;
        size--;

        return;
    }

    int front()
    {
        if (!size)
        {
            throw runtime_error("Error: Out of Range\n");
        }

        return queue[head];
    }
};

int main()
{
    CircularQueue *q = new CircularQueue(5);

    for (int i = 1; i <= 7; i++)
    {
        try
        {
            q->enqueue(i);
            cout << q->front() << endl;
        }
        catch (runtime_error)
        {
            cout << "Error : Queue Overflow\n";
        }
    }

    for (int i = 1; i <= 7; i++)
    {
        try
        {
            q->dequeue();
            cout << q->front() << endl;
        }

        catch (runtime_error)
        {
            cout << "Error: Queue Underflow\n";
        }
    }

    q->enqueue(6);
    q->enqueue(7);
    cout << q->front() << endl;

    return 0;
}