#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> shoppingList;
    string item;
    int choice;

    do {
        cout << "\n--- SHOPPING LIST ---\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Search Item\n";
        cout << "4. Display All Items\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to add: ";
                cin.ignore();
                getline(cin, item);
                shoppingList.push_back(item);
                cout << "Item added successfully!\n";
                break;

            case 2:
                cout << "Enter item to remove: ";
                cin.ignore();
                getline(cin, item);

                {
                    auto it = find(shoppingList.begin(),
                                   shoppingList.end(), item);

                    if (it != shoppingList.end()) {
                        shoppingList.erase(it);
                        cout << "Item removed successfully!\n";
                    } else {
                        cout << "Item not found!\n";
                    }
                }
                break;

            case 3:
                cout << "Enter item to search: ";
                cin.ignore();
                getline(cin, item);

                if (find(shoppingList.begin(),
                         shoppingList.end(), item)
                    != shoppingList.end()) {
                    cout << "Item found in shopping list!\n";
                } else {
                    cout << "Item not found!\n";
                }
                break;

            case 4:
                cout << "\nShopping List:\n";

                if (shoppingList.empty()) {
                    cout << "List is empty.\n";
                } else {
                    for (int i = 0; i < shoppingList.size(); i++) {
                        cout << i + 1 << ". "
                             << shoppingList[i] << endl;
                    }
                }
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
