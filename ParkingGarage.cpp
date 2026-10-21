#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> cars;
    int choice, carNo;

    do {
        cout << "\n--- PARKING GARAGE ---\n";
        cout << "1. Park a car\n";
        cout << "2. Remove a car\n";
        cout << "3. Display parked cars\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter car number: ";
                cin >> carNo;
                cars.push(carNo);
                cout << "Car parked successfully.\n";
                break;

            case 2:
                if (cars.empty()) {
                    cout << "Parking garage is empty.\n";
                } else {
                    cout << "Car " << cars.top()
                         << " leaves the garage.\n";
                    cars.pop();
                }
                break;

            case 3:
                if (cars.empty()) {
                    cout << "No cars parked.\n";
                } else {
                    stack<int> temp = cars;
                    cout << "Cars (last entered first): ";
                    while (!temp.empty()) {
                        cout << temp.top() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
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
