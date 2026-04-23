#include <iostream>
#include <string>

using namespace std;

int main() {
    int choice; // Variable to store menu selection

    // Task 4: Wrap the logic in a do...while loop for a repeat menu [cite: 75-77]
    do {
        cout << "\n--- Secret Decoder Menu ---" << endl;
        cout << "1: decode a message" << endl;
        cout << "2: help (instructions)" << endl;
        cout << "0: exit" << endl;
        cout << "selection: ";
        cin >> choice;

        // Task 4: Use a switch to handle the user's choice [cite: 78-79]
        switch (choice) {
            case 1: {
                int seqSize;
                string RealResult = ""; 

                // Task 3: Use a while loop to validate length 
                cout << "how many numbers are in the secret sequence? ";
                cin >> seqSize;

                // Keeps asking until the user provides a positive number
                while (seqSize <= 0) {
                    cout << "error, invalid length. Enter a positive number: ";
                    cin >> seqSize;
                }

                // Task 2: Loop runs exactly 'seqSize' times [cite: 64-66]
                for (int i = 0; i < seqSize; i++) {
                    int code;
                    cout << "enter number " << (i + 1) << ": ";
                    cin >> code;

                    // Task 2: Off-by-one error fix (1:A, 2:B, etc.) [cite: 69-70]
                    if (code >= 1 && code <= 26) {
                        // Math: 'A' is ASCII 65. If code is 1, 65 + (1-1) = 65 ('A')
                        char ltr = (char)('A' + (code - 1));
                        RealResult += ltr;
                    } else {
                        // Invalid codes are treated as '?' [cite: 45]
                        RealResult += '?';
                    }
                }
                
                // Final output of the decoded word
                cout << "the decoded message is: " << RealResult << endl;
                break;
            }
            case 2:
                // Task 4: Behavior for option 2 (Help message) [cite: 81]
                cout << "instruction, numbers 1-26 map to letters A-Z. anythign else maps to '?'." << endl;
                break;
            case 0:
                // Task 4: Behavior for option 0 (Exit) [cite: 82]
                cout << "exiting program, bye!" << endl;
                break;
            default:
                // Task 4: Handle any other invalid input [cite: 83]
                cout << "Invalid option. Please show menu again." << endl;
                break;
        }
    } while (choice != 0); // Loop continues until user enters 0

    return 0;
}
