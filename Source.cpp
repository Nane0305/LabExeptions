
#include <iostream>
#include <exception> 

using namespace std;

template <typename T>
class Node
{
public:
    T value;
    Node* next;
    Node* prev;

    Node()
    {
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(T value) :Node()
    {
        this->value = value;
    }

    T GetValue()
    {
        return this->value;
    }
};

template <typename T>
class Stack
{
private:
    Node<T>* head;
    Node<T>* tail;
    uint32_t lenth;
public:
    Stack()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->lenth = 0;
    }

    bool Push(T elem)
    {
        Node<T>* node_elem = new Node<T>(elem);
        if (lenth == 0)
        {
            head = tail = node_elem;
        }
        else
        {
            tail->next = node_elem;
            node_elem->prev = tail;
            tail = node_elem;
        }
        lenth++;

        return true;
    }

    bool Pop()
    {
        Node<T>* node_elem = new Node<T>();
        node_elem = tail;
        tail = node_elem->prev;
        tail->next = nullptr;
        delete node_elem;
        return true;
    }

    uint32_t size()
    {
        throw (string)"Lenth is NULL.";
    }

    bool empty()
    {
        throw (string)"Lenth is NULL!";
    }

    T Top()
    {
        if (lenth == 0)
        {
            throw (string)"Lenth is NULL!!";
        }
        else
        {
            return tail->GetValue();
        }
    }
};

int main()
{
    try
    {
        Stack <int> stack;

        for (size_t i = 0; i < 10; i++)
        {
            stack.Push(i);
            cout << "Top [" << i << "] : " << stack.Top() << endl;
        }

        stack.Pop();
        cout << "Top : " << stack.Top() << endl;
        stack.Pop();
        cout << "Top : " << stack.Top() << endl;

        if (stack.empty())
        {
            throw (string)"Stack is empty!";
        }

        else
        {
            throw (string)"Stack is not empty!";
        }
    }

    catch (string line)
    {
        cout << line << endl;
    }

    catch (std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    cout << "Exit!" << endl;

    return 0;
}