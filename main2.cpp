#include <iostream>
#include <Windows.h>

using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <class T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void AddToHead(T data) {
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

    void AddToTail(T data) {
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

    void DeleteFromHead() {
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

    void DeleteFromTail() {
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

    void DeleteAll() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void Show() {
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


    void InsertAt(int pos, T data) {
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

    void RemoveAt(int pos) {
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

    int Find(T data) {
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

    int FindAndReplace(T data, T newData) {
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

    void Reverse() {
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

    int Size() {
        int count = 0;
        Node<T>* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DoublyLinkedList<int> list;

    int choice, data, pos, newData, count; 

    while (true) {
        cout << "1. Додати елемент до голови списку" << endl;
        cout << "2. Додати елемент до хвоста списку" << endl;
        cout << "3. Видалити елемент з голови списку" << endl;
        cout << "4. Видалити елемент з хвоста списку" << endl;
        cout << "5. Видалити всі елементи" << endl;
        cout << "6. Вивести список на екран" << endl;
        cout << "7. Вставити елемент в задану позицію" << endl;
        cout << "8. Видалити елемент з заданої позиції" << endl;
        cout << "9. Пошук заданого елемента" << endl;
        cout << "10. Пошук і заміна заданого елемента" << endl;
        cout << "11. Перевернути список" << endl;
        cout << "0. Вихід" << endl;

        cout << "Введіть номер операції: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть дані: ";
            cin >> data;
            list.AddToHead(data);
            break;
        case 2:
            cout << "Введіть дані: ";
            cin >> data;
            list.AddToTail(data);
            break;
        case 3:
            list.DeleteFromHead();
            break;
        case 4:
            list.DeleteFromTail();
            break;
        case 5:
            list.DeleteAll();
            break;
        case 6:
            list.Show();
            break;
        case 7:
            cout << "Введіть позицію: ";
            cin >> pos;
            cout << "Введіть дані: ";
            cin >> data;
            list.InsertAt(pos, data);
            break;
        case 8:
            cout << "Введіть позицію: ";
            cin >> pos;
            list.RemoveAt(pos);
            break;
        case 9:
            cout << "Введіть дані: ";
            cin >> data;
            pos = list.Find(data);
            if (pos == -1) {
                cout << "Елемент не знайдено!" << endl;
            }
            else {
                cout << "Елемент знайдено на позиції " << pos << endl;
            }
            break;
        case 10:
            cout << "Введіть дані для пошуку: ";
            cin >> data;
            cout << "Введіть дані для заміни: ";
            cin >> newData;
            count = list.FindAndReplace(data, newData); 
            if (count == 0) {
                cout << "Елемент не знайдено!" << endl;
            }
            else {
                cout << "Замінено " << count << " елементів" << endl;
            }
            break;
        case 11:
            list.Reverse();
            break;
        case 0:
            return 0;
        default:
            cout << "Невірна операція!" << endl;
        }
    }
    return 0;
}
