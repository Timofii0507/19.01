#include <iostream>
#include <stdexcept>
#include <Windows.h>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node() {
        prev = nullptr;
        next = nullptr;
    }

    Node(T data, Node* prev, Node* next) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

template <typename T>
class Array {
    Node<T>* head;
    Node<T>* tail;
    int size;
    int grow;

public:
    Array() {
        head = nullptr;
        tail = nullptr;
        size = 0;
        grow = 1;
    }

    Array(int grow) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        this->grow = grow;
    }

    ~Array() {
        RemoveAll();
    }

    int GetSize() const {
        return size;
    }

    void SetSize(int size, int grow = 1) {
        this->grow = grow;
        if (size > this->size) {
            for (int i = this->size; i < size; i++) {
                T value;
                cout << "¬вед≥ть елемент " << i + 1 << ": ";
                cin >> value;
                Add(value);
            }
        }
        else if (size < this->size) {
            for (int i = this->size - 1; i >= size; i--) {
                RemoveAt(i);
            }
        }
    }

    int GetUpperBound() const {
        return size - 1;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void FreeExtra() {
    }

    void RemoveAll() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    T GetAt(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("≤ндекс за межами д≥апазону");
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void SetAt(int index, T value) {
        if (index < 0 || index >= size) {
            throw out_of_range("≤ндекс за межами д≥апазону");
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = value;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("≤ндекс за межами д≥апазону");
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void Add(T value) {
        if (tail != nullptr) {
            Node<T>* temp = new Node<T>(value, tail, nullptr);
            tail->next = temp;
            tail = temp;
        }
        else {
            head = new Node<T>(value, nullptr, nullptr);
            tail = head;
        }
        size++;
    }

    void Append(const Array<T>& other) {
        for (int i = 0; i < other.GetSize(); i++) {
            Add(other[i]);
        }
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            RemoveAll();
            Append(other);
        }
        return *this;
    }

    void Remove(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("≤ндекс за межами д≥апазону");
        }
        RemoveAt(index, 1);
    }

private:
    void InsertAt(int index, T value, int count = 1) {
        if (index < 0 || index > GetUpperBound()) {
            throw out_of_range("≤ндекс за межами д≥апазону");
        }
        if (count < 0) {
            throw invalid_argument("¬ведено в≥д'Їмне значенн€");
        }

        if (index == GetUpperBound() + 1) {
            for (int i = 0; i < count; i++) {
                Add(value);
            }
        }
        else {
            Node<T>* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            for (int i = 0; i < count; i++) {
                Node<T>* node = new Node<T>(value, temp->prev, temp);
                if (temp->prev != nullptr) {
                    temp->prev->next = node;
                }
                else {
                    head = node;
                }
                temp->prev = node;
                temp = temp->next;
                size++;
            }
        }
    }

    void RemoveAt(int index, int count = 1) {
        if (index < 0 || index >= GetSize()) {
            throw out_of_range("≤ндекс за межами д≥апазону");
        }
        if (count < 0) {
            throw invalid_argument("¬ведено в≥д'Їмне значенн€");
        }

        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        for (int i = 0; i < count; i++) {
            Node<T>* next = temp->next;
            if (temp->prev != nullptr) {
                temp->prev->next = next;
            }
            else {
                head = next;
            }
            if (next != nullptr) {
                next->prev = temp->prev;
            }
            else {
                tail = temp->prev;
            }
            delete temp;
            temp = next;
            size--;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Array<int> arr;

    int size;
    cout << "¬вед≥ть розм≥р масиву: ";
    cin >> size;

    arr.SetSize(size);

    for (int i = 0; i < arr.GetSize(); i++) {
        int value;
        cout << "¬вед≥ть елемент " << i + 1 << ": ";
        cin >> value;
        arr[i] = value;
    }

    cout << "≈лементи масиву: ";
    for (int i = 0; i < arr.GetSize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
