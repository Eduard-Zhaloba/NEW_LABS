#pragma once
#include <memory>
using namespace std;
template <typename T>
struct Node2 {
    T data;
    unique_ptr<Node2<T>> next;
    Node2<T>* prev;
};