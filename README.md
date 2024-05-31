# ATM Simulator Software Documentation

## Introduction

Welcome to the ATM Simulator Software, a professional-grade tool designed to simulate the operations of an Automated Teller Machine (ATM). This software allows users to configure the note denominations available in the ATM and simulate cash withdrawals, providing detailed output on the distribution of notes. The software is user-friendly, robust, and designed to handle typical scenarios encountered in ATM operations. Whether you're testing ATM functionalities or training staff, this simulator is an invaluable tool.

## Features

- **Customizable Note Denominations:** Allows users to register unique note values.
- **Simulated Withdrawals:** Accurately calculates and displays the number of each note dispensed for a given amount.
- **User-Friendly Interface:** Clear prompts and error messages ensure a smooth user experience.
- **Robust Error Handling:** Validates inputs and ensures withdrawals can be completed with the available notes.

## Code Documentation

### Libraries and Constants

```cpp
#include <iostream>
#include <set>
using namespace std;

const int NUM_NOTES = 4;
```

- **Libraries:**
  - `iostream` is included for input and output operations.
  - `set` is included to ensure unique note values.
- **Constants:**
  - `NUM_NOTES` defines the number of different note denominations the ATM can handle.

### Function: countNotes

```cpp
bool countNotes(int noteCount[NUM_NOTES], const int noteValues[NUM_NOTES], int amount) {
    for (int i = 0; i < NUM_NOTES; i++) {
        noteCount[i] = amount / noteValues[i];
        amount %= noteValues[i];
    }
    return amount == 0; // Return true if the amount can be dispensed exactly
}
```

- **Purpose:** Calculates the number of each note required to dispense a specified amount.
- **Parameters:**
  - `noteCount`: Array to store the count of each note.
  - `noteValues`: Array containing the values of the notes.
  - `amount`: The amount to be withdrawn.
- **Returns:** `true` if the amount can be dispensed exactly with the available notes; `false` otherwise.
- **Details:** Iterates through each note denomination, calculating how many notes of each type are needed and updating the remaining amount.

### Function: registerNotes

```cpp
void registerNotes(int noteValues[NUM_NOTES]) {
    cout << "=================================\n";
    cout << "Register the values of the notes\n";
    cout << "=================================\n";
    set<int> uniqueValues; // To ensure note values are unique
    for (int i = 0; i < NUM_NOTES; i++) {
        int noteValue;
        while (true) {
            cout << "Enter the value of note " << (i + 1) << ": ";
            cin >> noteValue;
            if (noteValue <= 0) {
                cout << "Error: Note value must be a positive integer. Try again.\n";
            } else if (uniqueValues.count(noteValue)) {
                cout << "Error: Note value must be unique. Try again.\n";
            } else {
                noteValues[i] = noteValue;
                uniqueValues.insert(noteValue);
                break;
            }
        }
    }
    cout << "=================================\n";
}
```

- **Purpose:** Allows users to register unique values for each note denomination.
- **Parameters:** 
  - `noteValues`: Array to store the registered note values.
- **Details:** Ensures each note value is a positive integer and that all note values are unique by using a `set`.

### Function: simulateOutput

```cpp
void simulateOutput(const int noteCount[NUM_NOTES], const int noteValues[NUM_NOTES]) {
    cout << "=================================\n";
    for (int i = 0; i < NUM_NOTES; i++) {
        cout << "Number of " << noteValues[i] << " notes: " << noteCount[i] << "\n";
    }
    cout << "=================================\n";
}
```

- **Purpose:** Displays the number of each note required to dispense the specified amount.
- **Parameters:**
  - `noteCount`: Array containing the count of each note.
  - `noteValues`: Array containing the values of the notes.
- **Details:** Outputs the count and value of each note in a formatted manner.

### Main Function

```cpp
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

        if (amount <= 0) {
            cout << "Error: Amount to be withdrawn must be a positive integer. Try again.\n";
            continue;
        }

        // Execute functions to count the number of notes by their value
        if (countNotes(noteCount, noteValues, amount)) { // Count notes by value
            simulateOutput(noteCount, noteValues); // Simulate output of notes
        } else {
            cout << "Error: The amount cannot be dispensed with the available notes. Try a different amount.\n";
        }
    }

    // End of main
    return 0;
}
```

- **Purpose:** Controls the flow of the program.
- **Initialization:**
  - `amount` stores the amount to be withdrawn.
  - `exitSystem` flag for exiting the main loop.
  - `noteCount` and `noteValues` arrays for storing note counts and values.
- **Process:**
  - Calls `registerNotes` to initialize note values.
  - Enters a loop to process withdrawal requests.
  - Checks for the special exit code (`9999`) to terminate the program.
  - Validates the withdrawal amount and calls appropriate functions to count and display notes.
  - Handles errors if the amount cannot be dispensed with the available notes.

## Conclusion

This ATM Simulator Software is designed to be a reliable and user-friendly tool for simulating ATM operations. With its robust error handling and clear user interface, it ensures a smooth and realistic experience for users. Whether used for testing, training, or educational purposes, this software is a valuable asset for anyone involved in ATM management and operations.
