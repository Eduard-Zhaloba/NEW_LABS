#pragma once
#include "Single_Node.h"
#include <ostream>
#include <memory>

template <typename T> class SinglyLinkedList;

template <typename T>
std::ostream& operator<<(std::ostream& out, const SinglyLinkedList<T>& list);

template <typename T>
class SinglyLinkedList {
private:
    std::unique_ptr<Node<T>> head;
    int size = 0;
public:
    SinglyLinkedList(T data);
    void push_front(T data);
    void push_back(T value);
    void delete_front();

    friend std::ostream& operator<< <T>(std::ostream& out, const SinglyLinkedList<T>& list);
};
