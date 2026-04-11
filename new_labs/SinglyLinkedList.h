#include "Single_Node.h"

template <typename T>
class SinglyLinkedList {
private:
    unique_ptr<Node<T>> head;
    int size = 0;
public:
    SinglyLinkedList(T data);
    void push_front(T data);
    void delete_front();
    void print();
    
    //int findElement(T data);
};

