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
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void add(const T& data) {
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

    void print() const {
        if (isEmpty()) {
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

    LinkedList<T>& clone() {
        LinkedList<T>* newList = new LinkedList<T>();

        Node<T>* temp = head;
        while (temp != nullptr) {
            newList->add(temp->data);
            temp = temp->next;
        }

        return *newList;
    }

    LinkedList<T> operator+(const LinkedList<T>& other) const {
        LinkedList<T> newList;

        Node<T>* temp1 = head;
        while (temp1 != nullptr) {
            newList.add(temp1->data);
            temp1 = temp1->next;
        }

        Node<T>* temp2 = other.head;
        while (temp2 != nullptr) {
            newList.add(temp2->data);
            temp2 = temp2->next;
        }

        return newList;
    }

    LinkedList<T> operator*(const LinkedList<T>& other) const {
        LinkedList<T> newList;

        Node<T>* temp1 = head;
        while (temp1 != nullptr) {
            Node<T>* temp2 = other.head;
            while (temp2 != nullptr) {
                if (temp1->data == temp2->data) {
                    newList.add(temp1->data);
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }

        return newList;
    }

    int length() const {
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void insert(int index, const T& data) {
        if (index < 0 || index > length()) {
            cout << "Невірний індекс!" << endl;
            return;
        }

        Node<T>* newNode = new Node<T>(data);

        if (index == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (index == length()) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            Node<T>* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void remove(int index) {
        if (index < 0 || index >= length()) {
            cout << "Невірний індекс!" << endl;
            return;
        }

        if (isEmpty()) {
            cout << "Список порожній!" << endl;
            return;
        }

        if (index == 0) {
            Node<T>* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete temp;
        }
        else if (index == length() - 1) {
            Node<T>* temp = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
            delete temp;
        }
        else {
            Node<T>* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }

            Node<T>* toDelete = temp->next;
            temp->next = toDelete->next;
            temp->next->prev = temp;
            delete toDelete;
        }
    }

    void clear() {
        while (!isEmpty()) {
            remove(0);
        }
    }

    friend ostream& operator<<(ostream& os, const LinkedList<T>& list) {
        if (list.isEmpty()) {
            os << "Список порожній!" << endl;
            return os;
        }

        Node<T>* temp = list.head;
        while (temp != nullptr) {
            os << temp->data << " ";
            temp = temp->next;
        }
        os << endl;
        return os;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    LinkedList<int> list1;
    int value;
    char choice;

    do {
        cout << "Введіть значення для списку 1: ";
        cin >> value;
        list1.add(value);
        cout << "Продовжити введення для списку 1? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    LinkedList<int> list2;

    do {
        cout << "Введіть значення для списку 2: ";
        cin >> value;
        list2.add(value);
        cout << "Продовжити введення для списку 2? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    cout << "Список 1: " << list1;
    cout << "Список 2: " << list2;

    LinkedList<int>& list3 = list1.clone();
    cout << "Клонований список: " << list3;

    LinkedList<int> list4 = list1 + list2;
    cout << "Список 1 + Список 2: " << list4;

    LinkedList<int> list5 = list1 * list2;
    cout << "Список 1 * Список 2: " << list5;

    int index;
    cout << "Введіть індекс для вставки у список 1: ";
    cin >> index;
    cout << "Введіть значення для вставки у список 1: ";
    cin >> value;
    list1.insert(index, value);
    cout << "Список 1 після вставки: " << list1;

    cout << "Введіть індекс для видалення зі списку 2: ";
    cin >> index;
    list2.remove(index);
    cout << "Список 2 після видалення: " << list2;

    list3.clear();
    cout << "Клонований список після очищення: " << list3;

    return 0;
}
