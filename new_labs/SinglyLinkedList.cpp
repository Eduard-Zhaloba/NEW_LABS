#include "SinglyLinkedList.h"
#include <iostream>
#include <memory>


using namespace std;

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(): head(nullptr), size(0) {};
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(T data) {
    head = std::make_unique<Node<T>>();
    head->data = data;
    head->next = nullptr;
    size = 1;
}
template <typename T>
void SinglyLinkedList<T>::remove(int index) {
    if (index == 0) {
        delete_front();
        return;
    }
    if (index > 0 and index < size) {
        Node<T>* current = head.get();
        for (int i = 0; i < index - 1; ++i) {
            current = current->next.get();
        }
        std::unique_ptr<Node<T>> temp = std::move(current->next);
        temp= std::move(temp->next);
        current->next = std::move(temp);
        size--;
    }
     else {
		cout << "\nError: Index is out of bounds!" << endl;
    }
}
template <typename T>
void SinglyLinkedList<T>::insert(int index, T data) {
    
   
    if (index == 0) {
        push_front(data);
       
    }
    if (index > 0 and index < size) {
        auto newNode = std::make_unique<Node<T>>(data);
        Node<T>* current = head.get();
        for (int i = 0; i < index - 1; ++i) {
            current = current->next.get();
        }
        newNode->next = std::move(current->next);
        current->next = std::move(newNode);
        size++;
    }
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
    if (size > 0) {
        head = std::move(head->next);
        --size;
    } else {
        cout << "\nError: You are trying to delete an element from an empty list!" << endl;
    }
}

template <typename T>
void SinglyLinkedList<T>::delete_back() {
    
    //if (!head) {
        //throw 0;
    //}
    if (size>0){
        int i = 0;
        Node<T>* current = head.get();
        while (i != size - 1) {
            current = current->next.get();
            i = i + 1;
        }
        current->next = nullptr;
        --size;
    }
    else {
        cout << "\nError: You are trying to delete an element from an empty list!" << endl;
    }
  
	
}


template <typename T>
void SinglyLinkedList<T>::find(T element) {
    Node<T>* current = head.get();
    int index = 0;
    while (current!=nullptr) {
        if (current->data == element) {
            cout << "Element " << element << " found at index: " << index << endl;
            return;
        }
        current = current->next.get();
        index++;
    }
	cout << "Element " << element << " not found in the list." << endl;
}

template <typename T>
void SinglyLinkedList<T>::get_value(int index) {
   
    if (size>0 and index >= 0 and index < size){
        
    Node<T>* current = head.get(); 
    for (int i = 0; i < index; ++i) {
        current = current->next.get();
    }

    cout <<"Your element: " << current->data << endl;
    }
    //else {
        //cout << "List is empty or index is out of bounds" << endl;
    //}
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const SinglyLinkedList<T>& list){
    int k = 0;
    Node<T>* current = list.head.get();
    if (list.size == 0) {
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
        out<<"Number of elements: "<< list.size << endl;
        return out;
    }
}
template class SinglyLinkedList<int>;
template std::ostream& operator<< <int>(std::ostream& out, const SinglyLinkedList<int>& list);
template class SinglyLinkedList<char>;
template std::ostream& operator<< <char>(std::ostream& out, const SinglyLinkedList<char>& list);