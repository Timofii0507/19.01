#ifndef DOUBLYLINKEDLIST2_H
#define DOUBLYLINKEDLIST2_H

#include "Node2.h"

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
    void InsertAt(int pos, T data);
    void RemoveAt(int pos);
    int Find(T data);
    int FindAndReplace(T data, T newData);
    void Reverse();
    int Size();
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

template <class T>
void DoublyLinkedList<T>::InsertAt(int pos, T data) {
    if (pos < 0 || pos > Size()) {
        cout << "Невірна позиція!" << endl;
        return;
    }

    Node<T>* newNode = new Node<T>(data);
    Node<T>* temp = head;

    if (pos == 0) {
        AddToHead(data);
        return;
    }

    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == tail) {
        AddToTail(data);
        return;
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

template <class T>
void DoublyLinkedList<T>::RemoveAt(int pos) {
    if (pos < 0 || pos >= Size()) {
        cout << "Невірна позиція!" << endl;
        return;
    }

    Node<T>* temp = head;

    if (pos == 0) {
        DeleteFromHead();
        return;
    }

    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == tail) {
        DeleteFromTail();
        return;
    }

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
}

template <class T>
int DoublyLinkedList<T>::Find(T data) {
    Node<T>* temp = head;
    int pos = 0;

    while (temp != nullptr) {
        if (temp->data == data) {
            return pos;
        }
        pos++;
        temp = temp->next;
    }

    return -1;
}

template <class T>
int DoublyLinkedList<T>::FindAndReplace(T data, T newData) {
    Node<T>* temp = head;
    int count = 0;

    while (temp != nullptr) {
        if (temp->data == data) {
            temp->data = newData;
            count++;
        }
        temp = temp->next;
    }

    return count;
}

template <class T>
void DoublyLinkedList<T>::Reverse() {
    Node<T>* temp = head;
    Node<T>* prev = nullptr;

    while (temp != nullptr) {
        Node<T>* next = temp->next;
        temp->next = prev;
        temp->prev = next;
        prev = temp;
        temp = next;
    }

    head = prev;
}

template <class T>
int DoublyLinkedList<T>::Size() {
    int count = 0;
    Node<T>* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

#endif