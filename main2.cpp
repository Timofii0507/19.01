#include <Windows.h>
#include "DoublyLinkedList2.h"

int main() {
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
