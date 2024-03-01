#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(const T& data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void enqueue(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Черга порожня!" << endl;
            return T();
        }

        Node<T>* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        else {
            head->prev = nullptr;
        }
        delete temp;

        return temp->data;
    }

    void print() {
        if (isEmpty()) {
            cout << "Черга порожня!" << endl;
            return;
        }

        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Queue<int> queue;

    int n;
    cout << "Введіть кількість елементів: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Введіть елемент #" << i + 1 << ": ";
        cin >> value;
        queue.enqueue(value);
    }

    cout << "Черга: ";
    queue.print();

    cout << "Видаляємо елементи..." << endl;
    while (!queue.isEmpty()) {
        cout << queue.dequeue() << " ";
    }

    cout << endl << "Черга: ";
    queue.print();

    return 0;
}
