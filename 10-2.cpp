#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> shelf[10];

    int n;
    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int code;
        cout << "Enter book code: ";
        cin >> code;

        int index = code % 10;
        shelf[index].push_back(code);
    }

    cout << "\nFinal Contents of Shelves:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << " : ";

        if (shelf[i].empty()) {
            cout << "Empty";
        } else {
            for (int j = 0; j < shelf[i].size(); j++) {
                cout << shelf[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}