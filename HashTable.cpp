#include <iostream>
using namespace std;

#define SIZE 10

int table[SIZE];

void insert(int x) {
    int index = x % SIZE;

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos] == -1) {
            table[pos] = x;
            cout << "Account inserted successfully.\n";
            return;
        }

        if (table[pos] == x) {
            cout << "Account already exists.\n";
            return;
        }
    }

    cout << "Hash table is full.\n";
}

void search(int x) {
    int index = x % SIZE;

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos] == -1) {
            cout << "Account not found.\n";
            return;
        }

        if (table[pos] == x) {
            cout << "Account found at index "
                 << pos << ".\n";
            return;
        }
    }

    cout << "Account not found.\n";
}

void display() {
    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }
}

int main() {
    int choice, x;

    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    do {
        cout << "\n1. INSERT\n";
        cout << "2. SEARCH\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> x;
                insert(x);
                break;

            case 2:
                cout << "Enter account number to search: ";
                cin >> x;
                search(x);
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
