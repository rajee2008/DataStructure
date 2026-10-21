#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> history;

    history.push("google.com");
    history.push("youtube.com");
    history.push("abcsc.com");
    history.push("facebook.com");

    cout << "Browser history is loaded.\n";

    // Press Back once
    history.pop();
    cout << "Back pressed once.\n";

    // Press Back twice
    history.pop();
    cout << "Back pressed twice.\n";

    cout << "Current top page: " << history.top() << endl;

    return 0;
}
