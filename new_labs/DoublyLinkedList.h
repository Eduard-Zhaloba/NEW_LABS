#pragma once
#include "Double_Node.h"
#include <ostream>
#include <memory>

template <typename T> class DoublyLinkedList;

template <typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& list);

template <typename T>
class DoublyLinkedList {
private:
    std::unique_ptr<Node2<T>> head;
    Node2<T>* tail;
    int size = 0;
public:
    DoublyLinkedList();
};