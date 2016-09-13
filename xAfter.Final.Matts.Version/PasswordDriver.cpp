/*File Name: PasswordDriver.cpp

 Author: Shane Fleming
 Date: 03/11/16
 Assignment Number: 4
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman

 Password Manager, contains int main(), driver for Manager*/

#include <iostream>
#include "PasswordManager.h"
#include <fstream>

using namespace std;

/******************************************************************
 loadPasswordFromFile: Checks for password.txt file and inputs encrypted
    password, otherwise sets DEFAULT_PASSWORD
 returns: string with either default password/or password from file
 ******************************************************************/

string loadPasswordFromFile()
{
    ifstream fin("password.txt");           //fin for inputting from file
    string temp = "";  //temp to hold password for passing

    getline(fin, temp); // get line from password.txt and place in temp

    return temp;
}

/******************************************************************
 savePasswordToFile: saves encrypted password to password.txt
 returns: NO RETURN Void Function
 ******************************************************************/

void savePasswordToFile(PasswordManager manager)
{
    ofstream fout("password.txt");          //fout for outputting to file

    fout << manager.getEncryptedPassword() << endl;
}

/******************************************************************
 main: Loop for switch menu, inputs and outputs to monitor
 calls necessary functions
 returns: 0
 ******************************************************************/

int main ()
{
    char userChoice;        //stores users choice
    string tempPassword;    //stores users password to encrypt
    bool respon;
    string loadedPassword = loadPasswordFromFile();
    PasswordManager manager(loadedPassword); //instance of class PasswordManager, called manager


    if(loadedPassword.empty()) {
        cout << endl << "No password.txt found, your default password "
            << "is \"" << PasswordManager::DEFAULT_PASSWORD << "\"" << endl;
    }

    do
    {
        cout << endl << "Password Utilities:" << endl
        << "A. Change Password" << endl
        << "B. Validate Password" << endl
        << "C. Quit" << endl
        << "Enter your choice: ";

        cin >> userChoice;

        switch (userChoice)
        {
            case 'a':
            case 'A':
                cout << endl << "Must be at least 8 characters long and "
                << "contain at least three out of the following." << endl
                << "  - Uppercase letters" << endl
                << "  - Lowercase letters" << endl
                << "  - Numbers" << endl
                << "  - Symbols" << endl;

                cout << "Please Enter New Password: ";

                cin >> tempPassword;

                respon = manager.setNewPassword(tempPassword);

                if (respon == true)
                    cout << "Password changed successfully." << endl;
                else
                    cout << "Password entered does not meet standards." << endl;

                break;

            case 'b':
            case 'B':
                cout << "Please enter your password: ";
                cin >> tempPassword;

                if(manager.validatePassword(tempPassword))
                {
                    cout << endl << "Your password is correct." << endl;
                }
                else
                {
                    cout << endl << "Your password is incorrect." << endl;
                }

                break;

            case 'c':
            case 'C':
                savePasswordToFile(manager.getEncryptedPassword());
                cout << endl << "Terminating program..." << endl << endl;
                return 0;

            default:
                cout << "Error Please Try Again" << endl;
        }
    }
    while(true);

    return 0;
}
