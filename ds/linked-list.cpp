/**
 * @file linked-list.cpp
 * @author Lasindu Weerasinghe
 * @brief LinkedList with its complex algorithms
 * @date 2022-09-03
 */

#include <iostream>

class Node
{
public:
    int data;
    Node *next = nullptr;

    Node(int data) : data(data)
    {
    }
};

class LinkedList
{
private:
    Node *head = nullptr;

public:
    LinkedList() {}
    LinkedList(int arr[], int len);
    ~LinkedList();

    void addToBottom(int data);
    void removeFromBottom();
    void print();
    LinkedList *reverse();
};

void LinkedList::addToBottom(int data)
{
    Node *ptr = new Node(data);

    if (head == nullptr)
    {
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
}

void LinkedList::removeFromBottom()
{
    auto top = head;

    head = top->next;

    delete top;
}

void LinkedList::print()
{
    auto next = head;

    while (next != nullptr)
    {
        std::cout << next->data << " ";
        next = next->next;
    }
}

LinkedList *LinkedList::reverse()
{
    LinkedList *list = new LinkedList();

    for (auto n = head; n != nullptr; n = n->next)
    {
        list->addToBottom(n->data);
    }

    return list;
}

LinkedList::LinkedList(int arr[], int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        addToBottom(arr[i]);
    }
}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        removeFromBottom();
    }
}

int main()
{
    int arr[] = {10, 20, 5, 4, 99};
    const int len = sizeof(arr) / sizeof(arr[0]);

    LinkedList list(arr, len);
    std::cout << "Original:  ";
    list.print();

    auto revered = list.reverse();
    std::cout << '\n'
              << "Reversed:  ";
    revered->print();

    delete revered;

    return 0;
}