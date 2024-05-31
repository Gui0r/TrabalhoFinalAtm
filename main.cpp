#include <iostream>
#include <string>
using namespace std;

const int NUM_NOTES = 4;

// Function to count the number of notes by value
void countNotes(int noteCount[NUM_NOTES], const int noteValues[NUM_NOTES], int amount) {
    for (int i = 0; i < NUM_NOTES; i++) {
        noteCount[i] = amount / noteValues[i];
        amount %= noteValues[i];
    }
}

// Function to register the note values
void registerNotes(int noteValues[NUM_NOTES]) {
    cout << "=================================\n";
    cout << "Register the values of the notes\n";
    cout << "=================================\n";
    for (int i = 0; i < NUM_NOTES; i++) {
        cout << "Enter the value of the note: ";
        cin >> noteValues[i];
    }
    cout << "=================================\n";
}

// Function to simulate the output of notes
void simulateOutput(const int noteCount[NUM_NOTES], const int noteValues[NUM_NOTES]) {
    cout << "=================================\n";
    for (int i = 0; i < NUM_NOTES; i++) {
        cout << "Number of " << noteValues[i] << " notes: " << noteCount[i] << "\n";
    }
    cout << "=================================\n";
}

// Main function
int main() {
    int amount = 0;
    int exitSystem = 0;

    int noteCount[NUM_NOTES] = {0};
    int noteValues[NUM_NOTES] = {0};

    // Register note values
    registerNotes(noteValues); // Register values of the notes

    // Main loop of the simulator
    while (exitSystem != 1) {
        // Read the amount to be withdrawn from the ATM
        cout << "\n=================================\n";
        cout << "Enter the amount to be withdrawn: ";
        cin >> amount;

        if (amount == 9999) {
            exitSystem = 1;
            cout << "=================================\n";
            cout << "SYSTEM INTERRUPTED - CODE 9999\n";
            cout << "=================================\n";
            break;
        }

        // Execute functions to count the number of notes by their value
        countNotes(noteCount, noteValues, amount); // Count notes by value
        simulateOutput(noteCount, noteValues); // Simulate output of notes
    }

    // End of main
    return 0;
}
