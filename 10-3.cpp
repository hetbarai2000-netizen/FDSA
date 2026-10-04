#include <iostream>
using namespace std;

int main() {
    int table[10];

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int n;
    cout << "Enter number of student IDs: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int id;
        cout << "Enter student ID: ";
        cin >> id;

        int index = id % 10;         
        int step = 7 - (id % 7);     

        int start = index;

        while (table[index] != -1) {
            index = (index + step) % 10;

            if (index == start) {
                cout << "Hash table is full! Cannot insert " << id << endl;
                break;
            }
        }

        if (table[index] == -1)
            table[index] = id;
    }

    cout << "\nFinal Hash Table:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << " : ";
        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];
        cout << endl;
    }

    return 0;
}