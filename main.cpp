#include <iostream>
using namespace std;

const int NUM_NOTES = 6;
const int NOTE_VALUES[NUM_NOTES] = {100, 50, 20, 10, 5, 2};

// Function to count the number of notes by value
void countNotes(int noteCount[NUM_NOTES], int amount) {
    for (int i = 0; i < NUM_NOTES; i++) {
        noteCount[i] = amount / NOTE_VALUES[i];
        amount %= NOTE_VALUES[i];
    }
}

// Function to simulate the output of notes
void simulateOutput(const int noteCount[NUM_NOTES]) {
    cout << "Output:\n";
    for (int i = 0; i < NUM_NOTES; i++) {
        cout << "Number of R$" << NOTE_VALUES[i] << " notes: " << noteCount[i] << "\n";
    }
}

// Function to display menu options
int displayMenu() {
    int choice;
    cout << "\n===== Menu =====\n";
    cout << "1. Withdraw Amount\n";
    cout << "2. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Main function
int main() {
    int amount = 0;
    bool exitSystem = false;

    int noteCount[NUM_NOTES] = {0};

    do {
        int choice = displayMenu();

        switch (choice) {
            case 1:
                cout << "\nEnter the amount to be withdrawn (9999 to exit): ";
                cin >> amount;

                if (amount == 9999) {
                    exitSystem = true;
                    cout << "System interrupted - Code 9999\n";
                } else if (amount <= 0) {
                    cout << "Amount to be withdrawn must be a positive integer. Try again.\n";
                } else {
                    countNotes(noteCount, amount);
                    simulateOutput(noteCount);
                }
                break;
            case 2:
                exitSystem = true;
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (!exitSystem);

    return 0;
}
