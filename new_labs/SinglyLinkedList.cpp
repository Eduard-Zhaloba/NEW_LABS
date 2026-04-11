#include "SinglyLinkedList.h"
#include <iostream>
#include <memory>

using namespace std;
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(T data) {
    head = std::make_unique<Node<T>>();
    head->data = data;
    head->next = nullptr;
    size = 1;
}
template <typename T>
void SinglyLinkedList<T>::push_back(T value) {
    auto newNode = std::make_unique<Node<T>>();
    int p=0;
    newNode->data = value;
    newNode->next = nullptr;
    if (!head) {
        head = std::move(newNode);
    } else {
        Node<T>* current = head.get();
        while (p!=size-1) {
            current = current->next.get();
            p=p+1;
        }
        current->next = std::move(newNode);
    }
    ++size;
}
template <typename T>
void SinglyLinkedList<T>::push_front(T data) {
    auto newNode = std::make_unique<Node<T>>();
    newNode->data = data;
    newNode->next = std::move(head);
    head = std::move(newNode);
    ++size;
}
template <typename T>
void SinglyLinkedList<T>::delete_front() {
    if (!head) {
        throw std::out_of_range("List is empty! Cannot delete element.");
    }
    head = std::move(head->next);
    --size;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const SinglyLinkedList<T>& list){
    int k = 0;
    Node<T>* current = list.head.get();
    if (current == nullptr) {
        out << "List is empty" << std::endl;
        return out;
    }
    else{
        out << "Elements: [ ";

        while (k != list.size) {
            out << current->data;
            if (k != list.size - 1) {
                out << ", ";
            }
            current = current->next.get();
            k = k + 1;
        }

        out << " ]" << std::endl;
        return out;
    }
}
template class SinglyLinkedList<int>;
template std::ostream& operator<< <int>(std::ostream& out, const SinglyLinkedList<int>& list);
