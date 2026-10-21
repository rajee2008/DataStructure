#include <iostream>
using namespace std;

struct Coach {
    int coachNo;
    Coach* next;
};

Coach* head = NULL;

// Add coach at the beginning
void addBeginning(int n) {
    Coach* newCoach = new Coach;
    newCoach->coachNo = n;
    newCoach->next = head;
    head = newCoach;
    cout << "Coach added at beginning.\n";
}

// Add coach at the end
void addEnd(int n) {
    Coach* newCoach = new Coach;
    newCoach->coachNo = n;
    newCoach->next = NULL;

    if (head == NULL) {
        head = newCoach;
    } else {
        Coach* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newCoach;
    }
    cout << "Coach added at end.\n";
}

// Remove a coach by coach number
void removeCoach(int n) {
    Coach* temp = head;
    Coach* prev = NULL;

    while (temp != NULL && temp->coachNo != n) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Coach not found.\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Coach removed successfully.\n";
}

// Display all coaches
void display() {
    Coach* temp = head;

    if (temp == NULL) {
        cout << "Train has no coaches.\n";
        return;
    }

    cout << "Train: ";
    while (temp != NULL) {
        cout << "Coach" << temp->coachNo << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, n;

    do {
        cout << "\n--- TRAIN COACH MANAGEMENT ---\n";
        cout << "1. Add coach at beginning\n";
        cout << "2. Add coach at end\n";
        cout << "3. Remove a coach\n";
        cout << "4. Display all coaches\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter coach number: ";
                cin >> n;
                addBeginning(n);
                break;

            case 2:
                cout << "Enter coach number: ";
                cin >> n;
                addEnd(n);
                break;

            case 3:
                cout << "Enter coach number to remove: ";
                cin >> n;
                removeCoach(n);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
