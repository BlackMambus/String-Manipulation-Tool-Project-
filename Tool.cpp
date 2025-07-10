#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function declarations
void reverseString(string str);
void toUpperCase(string str);
void toLowerCase(string str);
void findSubstring(string str);
void replaceSubstring(string str);

int main() {
    string input;
    int choice;

    cout << "🔤 Welcome to the String Manipulation Tool 🔤\n";
    cout << "Enter a string: ";
    getline(cin, input);

    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Reverse String\n";
        cout << "2. Convert to UPPERCASE\n";
        cout << "3. Convert to lowercase\n";
        cout << "4. Find Substring\n";
        cout << "5. Replace Substring\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer

        switch (choice) {
            case 1: reverseString(input); break;
            case 2: toUpperCase(input); break;
            case 3: toLowerCase(input); break;
            case 4: findSubstring(input); break;
            case 5: replaceSubstring(input); break;
            case 6: cout << "👋 Exiting the tool. Goodbye!\n"; break;
            default: cout << "❌ Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Function definitions
void reverseString(string str) {
    reverse(str.begin(), str.end());
    cout << "🔁 Reversed String: " << str << endl;
}

void toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "🔠 Uppercase: " << str << endl;
}

void toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << "🔡 Lowercase: " << str << endl;
}

void findSubstring(string str) {
    string sub;
    cout << "Enter substring to find: ";
    getline(cin, sub);
    size_t pos = str.find(sub);
    if (pos != string::npos)
        cout << "✅ Substring found at position: " << pos << endl;
    else
        cout << "❌ Substring not found.\n";
}

void replaceSubstring(string str) {
    string toReplace, replacement;
    cout << "Enter substring to replace: ";
    getline(cin, toReplace);
    cout << "Enter replacement string: ";
    getline(cin, replacement);

    size_t pos = str.find(toReplace);
    if (pos != string::npos) {
        str.replace(pos, toReplace.length(), replacement);
        cout << "🔁 Updated String: " << str << endl;
    } else {
        cout << "❌ Substring not found.\n";
    }
}
