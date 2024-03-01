#include <Windows.h>
#include "DoublyLinkedList.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DoublyLinkedList<int> list;

    int choice, data;

    while (true) {
        cout << "1. ������ ������� �� ������ ������" << endl;
        cout << "2. ������ ������� �� ������ ������" << endl;
        cout << "3. �������� ������� � ������ ������" << endl;
        cout << "4. �������� ������� � ������ ������" << endl;
        cout << "5. �������� �� ��������" << endl;
        cout << "6. ������� ������ �� �����" << endl;
        cout << "0. �����" << endl;

        cout << "������ ����� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������ ���: ";
            cin >> data;
            list.AddToHead(data);
            break;
        case 2:
            cout << "������ ���: ";
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
            cout << "������ ��������!" << endl;
        }
    }

    return 0;
}
