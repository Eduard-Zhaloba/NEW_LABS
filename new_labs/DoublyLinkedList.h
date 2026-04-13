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
    void push_front2(T value);
    void push_back2(T value);
	void delete_front2();
    void delete_back2();
	void get_value2(int index);
    void insert2(int index, T data);
    void remove2(int index);
    friend std::ostream& operator<< <T>(std::ostream& out, const DoublyLinkedList<T>& list);

    
};