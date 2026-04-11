#include "SinglyLinkedList.h"
#include <iostream>
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(T data) {
    head = make_unique<Node<T>>(data);
    head->data = data;
    head->next = nullptr;
    size++;
}
template <typename T>
void SinglyLinkedList<T>::push_front(T value) {
    auto newNode = make_unique<Node<T>>(value);
    newNode->next = move(head);
    head = move(newNode);
    size++;
}
template <typename T>
void SinglyLinkedList<T>::delete_front() {
    //if (!head){
        //throw std::out_of_range("Список порожній! Неможливо видалити елемент.");
    //}
    head = move(head->next);
    size--;
}

template <typename T>
void SinglyLinkedList<T>::print(){
    int k=0;
    Node<T>* current = head.get();
    if (current == nullptr) {
        cout << "List is empty" << std::endl;
        return;
    }

    cout << "Elements: [ ";

 
    while (k != size) {
        cout << current->data;
        if (k != size - 1) {
            cout << ", ";
        }
        current = current->next.get();
        k=k+1;
    }

    cout << " ]" << endl;
}
template class SinglyLinkedList<int>;