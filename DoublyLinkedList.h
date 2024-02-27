#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"

template <class T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList();
    void AddToHead(T data);
    void AddToTail(T data);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAll();
    void Show();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
void DoublyLinkedList<T>::AddToHead(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <class T>
void DoublyLinkedList<T>::AddToTail(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <class T>
void DoublyLinkedList<T>::DeleteFromHead() {
    if (head == nullptr) {
        return;
    }
    else if (head == tail) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }
}

template <class T>
void DoublyLinkedList<T>::DeleteFromTail() {
    if (tail == nullptr) {
        return;
    }
    else if (head == tail) {
        head = tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
}

template <class T>
void DoublyLinkedList<T>::DeleteAll() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

template <class T>
void DoublyLinkedList<T>::Show() {
    if (head == nullptr) {
        cout << "Список порожній!" << endl;
        return;
    }

    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

#endif 