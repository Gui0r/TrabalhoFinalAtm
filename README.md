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
using namespace std;

const int NUM_NOTES = 4;
```

- **Libraries:**
  - `iostream` is included for input and output operations.
- **Constants:**
  - `NUM_NOTES` defines the number of different note denominations the ATM can handle. This is set to 4 in this example.

### Function: `countNotes`

```cpp
void countNotes(int noteCount[NUM_NOTES], const int noteValues[NUM_NOTES], int amount) {
    for (int i = 0; i < NUM_NOTES; i++) {
        noteCount[i] = amount / noteValues[i];
        amount %= noteValues[i];
    }
}
```

- **Purpose:** Calculates the number of each note required to dispense a specified amount.
- **Parameters:**
  - `noteCount`: Array to store the count of each note.
  - `noteValues`: Array containing the values of the notes.
  - `amount`: The amount to be withdrawn.
- **Details:** Iterates through each note denomination, calculating how many notes of each type are needed and updating the remaining amount.

### Function: `registerNotes`

```cpp
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
```

- **Purpose:** Allows users to register unique values for each note denomination.
- **Parameters:** 
  - `noteValues`: Array to store the registered note values.
- **Details:** Prompts the user to enter positive integer values for each note. If the entered value is not positive, an error message is displayed and the user is prompted again.

### Function: `simulateOutput`

```cpp
void simulateOutput(const int noteCount[NUM_NOTES], const int noteValues[NUM_NOTES]) {
    cout << "Output:\n";
    for (int i = 0; i < NUM_NOTES; i++) {
        cout << "Number of " << noteValues[i] << " notes: " << noteCount[i] << "\n";
    }
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
```

- **Purpose:** Controls the flow of the program.
- **Initialization:**
  - `amount` stores the amount to be withdrawn.
  - `exitSystem` is a boolean flag for exiting the main loop.
  - `noteCount` and `noteValues` are arrays for storing note counts and values.
- **Process:**
  - Calls `registerNotes` to initialize note values.
  - Enters a loop to process withdrawal requests.
  - Checks for the special exit code (`9999`) to terminate the program.
  - Validates the withdrawal amount and calls appropriate functions to count and display notes.
  - Handles errors if the amount cannot be dispensed with the available notes.

## Conclusion

This ATM Simulator Software is designed to be a reliable and user-friendly tool for simulating ATM operations. With its robust error handling and clear user interface, it ensures a smooth and realistic experience for users. Whether used for testing, training, or educational purposes, this software is a valuable asset for anyone involved in ATM management and operations.
