#include <iostream>
#include "PasswordManager.h"
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;
PasswordManager manager;

string loadPasswordFromFile()
{
    fin.open("password.txt");
    string loadPass = "test";
    if (fin >> loadPass)
    {
        return loadPass;}
    else
    {
        loadPass = DEFAULT_PASSWORD;
        manager.setNewPassword(loadPass);
        loadPass = manager.encrypted;
        return loadPass;
    }
    
}

void savePasswordToFile(PasswordManager manager)
{
    fout.open("password.txt");
    fout << manager.getEncryptedPassword() << endl;
}

int main ()
{
    //PasswordManager manager;
    char userChoice;
    string tempPassword;
    
    manager.encrypted = loadPasswordFromFile();
    //manager.setNewPassword(manager.encrypted);
    
    do
    {
        cout << endl << "Password Utilities:" << endl;
        cout << "A. Change Password" << endl;
        cout << "B. Validate Password" << endl;
        cout << "C. Quit" << endl;
        cout << "Enter your choice: ";
        
        cin >> userChoice;
        
        switch (userChoice) {
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
                
                manager.setNewPassword(tempPassword);
                
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
    } while(true);
    
    return 0;
}