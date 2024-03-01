#include <Windows.h>
#include "DoublyLinkedList.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DoublyLinkedList<int> list;

    int choice, data;

    while (true) {
        cout << "1. Додати елемент до голови списку" << endl;
        cout << "2. Додати елемент до хвоста списку" << endl;
        cout << "3. Видалити елемент з голови списку" << endl;
        cout << "4. Видалити елемент з хвоста списку" << endl;
        cout << "5. Видалити всі елементи" << endl;
        cout << "6. Вивести список на екран" << endl;
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
        case 0:
            return 0;
        default:
            cout << "Невірна операція!" << endl;
        }
    }

    return 0;
}
