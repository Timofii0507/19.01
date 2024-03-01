#include <Windows.h>
#include "DoublyLinkedList2.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DoublyLinkedList<int> list;

    int choice, data, pos, newData, count;

    while (true) {
        cout << "1. ������ ������� �� ������ ������" << endl;
        cout << "2. ������ ������� �� ������ ������" << endl;
        cout << "3. �������� ������� � ������ ������" << endl;
        cout << "4. �������� ������� � ������ ������" << endl;
        cout << "5. �������� �� ��������" << endl;
        cout << "6. ������� ������ �� �����" << endl;
        cout << "7. �������� ������� � ������ �������" << endl;
        cout << "8. �������� ������� � ������ �������" << endl;
        cout << "9. ����� �������� ��������" << endl;
        cout << "10. ����� � ����� �������� ��������" << endl;
        cout << "11. ����������� ������" << endl;
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
        case 7:
            cout << "������ �������: ";
            cin >> pos;
            cout << "������ ���: ";
            cin >> data;
            list.InsertAt(pos, data);
            break;
        case 8:
            cout << "������ �������: ";
            cin >> pos;
            list.RemoveAt(pos);
            break;
        case 9:
            cout << "������ ���: ";
            cin >> data;
            pos = list.Find(data);
            if (pos == -1) {
                cout << "������� �� ��������!" << endl;
            }
            else {
                cout << "������� �������� �� ������� " << pos << endl;
            }
            break;
        case 10:
            cout << "������ ��� ��� ������: ";
            cin >> data;
            cout << "������ ��� ��� �����: ";
            cin >> newData;
            count = list.FindAndReplace(data, newData);
            if (count == 0) {
                cout << "������� �� ��������!" << endl;
            }
            else {
                cout << "������� " << count << " ��������" << endl;
            }
            break;
        case 11:
            list.Reverse();
            break;
        case 0:
            return 0;
        default:
            cout << "������ ��������!" << endl;
        }
    }
    return 0;
}
