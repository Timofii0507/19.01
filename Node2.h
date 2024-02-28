#ifndef NODE2_H
#define NODE2_H

#include <iostream>

using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T data);
};

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
}

#endif