#include <iostream>
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
    cout << "Register the values of the notes:\n";
    for (int i = 0; i < NUM_NOTES; i++) {
        while (true) {
            cout << "Enter the value of note " << (i + 1) << ": ";
            cin >> noteValues[i];
            if (noteValues[i] > 0) break;
            cout << "Note value must be a positive integer. Try again.\n";
        }
    }
}

// Function to simulate the output of notes
void simulateOutput(const int noteCount[NUM_NOTES], const int noteValues[NUM_NOTES]) {
    cout << "Output:\n";
    for (int i = 0; i < NUM_NOTES; i++) {
        cout << "Number of " << noteValues[i] << " notes: " << noteCount[i] << "\n";
    }
}

// Main function
int main() {
    int amount = 0;
    bool exitSystem = false;

    int noteCount[NUM_NOTES] = {0};
    int noteValues[NUM_NOTES] = {0};

    // Register note values
    registerNotes(noteValues);

    // Main loop of the simulator
    while (!exitSystem) {
        // Read the amount to be withdrawn from the ATM
        cout << "\nEnter the amount to be withdrawn (9999 to exit): ";
        cin >> amount;

        if (amount == 9999) {
            exitSystem = true;
            cout << "System interrupted - Code 9999\n";
            break;
        }

        if (amount <= 0) {
            cout << "Amount to be withdrawn must be a positive integer. Try again.\n";
            continue;
        }

        // Execute functions to count the number of notes by their value
        countNotes(noteCount, noteValues, amount);
        simulateOutput(noteCount, noteValues);
    }

    return 0;
}
