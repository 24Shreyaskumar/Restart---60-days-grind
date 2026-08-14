#include <iostream>
#include <memory>
using namespace std;

class Node
{
public:
    int val;
    unique_ptr<Node> next;
    Node() : val(0), next(nullptr) {}
    Node(int val) : val(val), next(nullptr) {}
    Node(int val, unique_ptr<Node> next) : val(val), next(move(next)) {}
};

unique_ptr<Node> reverse(unique_ptr<Node> head)
{
    unique_ptr<Node> prev = nullptr;

    while (head)
    {
        unique_ptr<Node> next = move(head->next);
        head->next = move(prev);
        prev = move(head);
        head = move(next);
    }

    return prev;
}

void printList(unique_ptr<Node> head)
{
    while (head)
    {
        cout << head->val << " ";
        head = move(head->next);
    }
    cout << endl;
    return;
}

int main()
{
    unique_ptr<Node> head = make_unique<Node>(0);
    Node *cur = head.get();
    for (int i = 1; i <= 5; i++)
    {
        cur->next = make_unique<Node>(i);
        cur = cur->next.get();
    }
    head = reverse(move(head));
    printList(move(head));
}