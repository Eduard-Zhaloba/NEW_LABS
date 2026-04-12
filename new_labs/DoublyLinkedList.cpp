#include "DoublyLinkedList.h"
#include <iostream>
#include <memory>
using namespace std;

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {};
//template <typename T>