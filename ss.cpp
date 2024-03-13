#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    // Login credentials

    cout << "       Security System      " << endl;

    cout << " _________________________________" << endl;
    cout << "|        1. Register              |" << endl;
    cout << "|        2. Login                 |" << endl;
    cout << "|        3. Change Password       |" << endl;
    cout << "|        4. End Program           |" << endl;
    cout << "|_________________________________|" << endl;

    do {
        cout << endl << endl;
        cout << "Enter your choice : ";
        cin >> a;
        switch (a) {
            case 1: {
                cout << " ______________________________" << endl;
                cout << "|          1. Register         |" << endl;
                cout << "|______________________________|" << endl << endl;
                cout << "Please Enter Your username : ";
                cin >> name;
                cout << "Please Enter Your Password : ";
                cin >> password0;
                cout << "Please Enter Your age : ";
                cin >> age;

                ofstream of1;
                of1.open("file.txt", ios::app); // Open in append mode
                if (of1.is_open()) {
                    of1 << name << "\n";
                    of1 << password0 << "\n"; // Add a newline to separate data
                    of1 << age << "\n"; // Add a newline to separate data
                    of1.close(); // Close the file after writing
                    cout << "Registration Successful." << endl;
                }
                break;
            }

            case 2: {
                i = 0;
                cout << " ______________________________" << endl;
                cout << "|          2. Login            |" << endl;
                cout << "|______________________________|" << endl << endl;

                ifstream of2;
                of2.open("file.txt");
                cout << "Please enter the username : ";
                cin >> user;
                cout << "Please Enter the Password : ";
                cin >> pass;

                if (of2.is_open()) {
                    bool found = false; // Flag to track successful login
                    while (getline(of2, text)) {
                        creds[i] = text;
                        i++;
                        if (i == 2) { // Check credentials after reading username and password
                            if (user == creds[0] && pass == creds[1]) {
                                cout << "     Login Successful    ";
                                cout << endl << endl;
                                cout << "  Details : " << endl;
                                cout << "Username : " << user << endl;
                                cout << "Password : " << pass << endl;
                                found = true;
                                break; // Break out of the loop once logged in
                            }
                            i = 0; // Reset for next set of credentials
                        }
                    }
                    if (!found) {
                        cout << endl << endl;
                        cout << "---------- Incorrect Credentials -----------" << endl;
                    }
                    of2.close(); // Close the file after reading
                }
                break;
            }

            case 3: {
                cout << "----------Change Password----------" << endl;
                ifstream of0;
                of0.open("file.txt");
                cout << "Enter the old Password : ";
                cin >> old;
                if (of0.is_open()) {
                    bool found = false;
                    while (getline(of0, text)) {
                        cp[i] = text;
                        i++;
                        if (i == 2) {
                            if (old == cp[1]) {
                                cout << "Enter Your new Password : ";
                                cin >> password1;
                                cout << "Enter Your password again : ";
                                cin >> password2;
                                if (password1 == password2) {
                                    cp[1] = password1;
                                    found = true;
                                    cout << "Password changed successfully" << endl;
                                } else {
                                    cout << "Passwords do not match" << endl;
                                }
                                break; // No need to continue reading the file
                            }
                            i = 0;
                        }
                    }
                    of0.close();
                    if (found) {
                        // Rewrite the file with updated password
                        ofstream of1("file.txt");
                        if (of1.is_open()) {
                            of1 << cp[0] << endl;
                            of1 << cp[1] << endl;
                            of1.close();
                        }
                    } else {
                        cout << "Invalid old password" << endl;
                    }
                }
                break;
            }

            case 4: {
                cout << "____________Thank You!_____________" << endl;
                break;
            }

            default:
                cout << "Enter the valid choice";
        }
    } while (a != 4);
    return 0;
}
