#include <iostream>
using namespace std;

struct Node {
    string name;
    Node *next;
};

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void arrive(string patient) {
        Node *newNode = new Node;
        newNode->name = patient;
        newNode->next = NULL;

        if (front == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front Patient: " << front->name << endl;
    }

    void attend() {
        if (front == NULL) {
            cout << "No patients waiting!" << endl;
            return;
        }

        Node *temp = front;
        cout << "Attended Patient: " << front->name << endl;
        front = front->next;
        delete temp;

        if (front == NULL)
            rear = NULL;

        if (front != NULL)
            cout << "Front Patient: " << front->name << endl;
        else
            cout << "Ward Empty" << endl;
    }
};

int main() {
    Queue q;
    int choice;
    string patient;

    do {
        cout << "\n1. Arrive";
        cout << "\n2. Attend";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Patient Name: ";
            cin >> patient;
            q.arrive(patient);
            break;

        case 2:
            q.attend();
            break;

        case 3:
            cout << "Exit";
            break;

        default:
            cout << "Invalid Choice";
        }

    } while (choice != 3);

    return 0;
}