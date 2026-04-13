#include "DoublyLinkedList.h"
#include <iostream>
#include <memory>
using namespace std;
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {};

template <typename T>
void DoublyLinkedList<T>::remove2(int index) {
    if (index == 0) {
        delete_front2();
        return;
    }
    if (index > 0 and index < size) {
        Node2<T>* current = head.get();
        for (int i = 0; i < index - 1; ++i) {
            current = current->next.get();
        }
        std::unique_ptr<Node2<T>> temp = std::move(current->next);
        temp = std::move(temp->next);
		if (temp != nullptr) {
			temp->prev = current->next.get();
		}
        current->next = std::move(temp);
        size--;
    }
    else {
        cout << "\nError: Index is out of bounds!" << endl;
    }
}




template <typename T>
void DoublyLinkedList<T>::insert2(int index, T data) {
    if (index == 0) {
        push_front2(data);
    }
    if (index > 0 and index <= size) {
        auto newNode = std::make_unique<Node2<T>>();
        newNode->data = data;
        Node2<T>* current = head.get();
        for (int i = 0; i < index - 1; ++i) {
            current = current->next.get();
        }
        newNode->next = std::move(current->next);
        if (newNode->next!=nullptr) {
            newNode->next->prev = newNode.get();
        }
        newNode->prev = current;
        current->next = std::move(newNode);
        size++;
    }
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& list2) {
    Node2<T>* current = list2.head.get();
    int k=0;
    if (list2.size == 0) {
        out << "List is empty" << std::endl;
        return out;
    }
    else {
        out << "Elements: [ ";
        while (current) {
            out << current->data;
            if (k != list2.size - 1) {
                out << ", ";
            }
            current = current->next.get();
            k = k + 1;
        }
        out << " ]" << endl;
        out << "Number of elements: " << list2.size << endl;
    }
}

template <typename T>
void DoublyLinkedList<T>::get_value2(int index) {
    if (index >= size){
        cout << "Index out of bounds" << endl;
        return;
    }
    else{
        Node2<T>* current = head.get();
        for (int i = 0; i < index; ++i){
            current = current->next.get();
        }
        cout<<"Your element: " << current->data << endl;
    }
}
template <typename T>
void DoublyLinkedList<T>::delete_back2() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    }
    if (size == 1) {
        head=nullptr;
        tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    size--;
}
template <typename T>
void DoublyLinkedList<T>::delete_front2() {
    if (size == 0) {
        cout << "List is empty" << endl;
		return; 
    }
    if (size == 1) {
        head = nullptr;
        tail = nullptr;
        size--;
	}
    else {
        head = std::move(head->next);
        head->prev = nullptr;
        
        size--;
        //if (size == 0) {
            //tail = nullptr;
		//}
    }
    
}
template <typename T>
void DoublyLinkedList<T>::push_front2(T value) {
    auto newNode = std::make_unique<Node2<T>>();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    if (!head) {
        head = std::move(newNode);
        tail = head.get();
    }
    else {
        newNode->next = std::move(head);
        newNode->next->prev = newNode.get();
        head = std::move(newNode);
    }
    size++;
}
template <typename T>
void DoublyLinkedList<T>::push_back2(T value) {
    auto newNode = std::make_unique<Node2<T>>();
	newNode->data = value;
    Node2<T>* NodePtr = newNode.get();
    if (!tail) {
        head = std::move(newNode);
        tail = NodePtr;
    }
    else {
		newNode->prev = tail;
        tail->next = std::move(newNode);
        tail = NodePtr;
        //NodePtr->prev = tail;
        //tail->next = std::move(newNode);
        //tail = NodePtr;
    }
    size++;
}
template class DoublyLinkedList<int>;
template std::ostream& operator<< <int>(std::ostream& out, const DoublyLinkedList<int>& list);
//template <typename T>

