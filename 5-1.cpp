#include <iostream>
using namespace std;

struct Node
{
    string song;
    Node *prev;
    Node *next;
};

Node *head = NULL;

void addBeginning(string s)
{
    Node *temp = new Node;
    temp->song = s;
    temp->prev = NULL;
    temp->next = head;

    if (head != NULL)
    {
        head->prev = temp;
    }
    head = temp;
}

void addEnd(string s)
{
    Node *temp = new Node;
    temp->song = s;
    temp->next = NULL;

    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
        return;
    }

    Node *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    temp->prev = p;
}

void insertAfter(string key, string s)
{
    Node *p = head;

    while (p != NULL && p->song != key)
        p = p->next;

    if (p == NULL)
    {
        cout << "Song not found!"<<endl;
        return;
    }

    Node *temp = new Node;
    temp->song = s;
    temp->next = p->next;
    temp->prev = p;

    if (p->next != NULL)
        p->next->prev = temp;

    p->next = temp;
}
void deleteFirst()
{
    if (head == NULL)
    {
        cout << "Playlist is empty."<<endl;
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
    cout << "First song deleted."<<endl;
}


void countSongs()
{
    int count = 0;
    Node *p = head;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    cout << "Total Songs = " << count << endl;
}
void display()
{
    if (head == NULL)
    {
        cout << "Playlist is empty."<<endl;
        return;
    }

    Node *p = head;
    cout << "Playlist: ";

    while (p != NULL)
    {
        cout << p->song << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int choice;
    string song, key;

    do
    {
        cout << "\n--- Music Playlist Menu ---"<<endl;
        cout << "1. Add Song at Beginning"<<endl;
        cout << "2. Add Song at End"<<endl;
        cout << "3. Insert Song After Another Song"<<endl;
        cout << "4. Delete First Song"<<endl;
        cout << "5. Count Songs"<<endl;
        cout << "6. Display Playlist"<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter song name: ";
            cin >> song;
            addBeginning(song);
            display();
            break;

        case 2:
            cout << "Enter song name: ";
            cin >> song;
            addEnd(song);
            display();
            break;

        case 3:
            cout << "Enter existing song name: ";
            cin >> key;
            cout << "Enter new song name: ";
            cin >> song;
            insertAfter(key, song);
            display();
            break;

        case 4:
            deleteFirst();
            display();
            break;

        case 5:
            countSongs();
            break;

        case 6:
            display();
            break;

        case 7:
            cout << "Exiting..."<<endl;
            break;

        default:
            cout << "Invalid Choice!"<<endl;
        }

    } while (choice != 7);

    return 0;
}