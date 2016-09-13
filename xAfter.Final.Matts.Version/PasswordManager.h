/*File Name: PasswordManager.h

 Author: Shane Fleming
 Date: 03/11/16
 Assignment Number: 4
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman

 Password Manager, Header file containing the Class*/

#include <iostream>
#include <string>

using namespace std;

class PasswordManager
{
private:
    string encrypted;  //string to hold encryped password
    string encrypt(const string&);
    bool verifyPassword(const string&);

public:
    static const string DEFAULT_PASSWORD;
    PasswordManager();
    PasswordManager(string);
    bool setNewPassword(const string&);

    /******************************************************************
     getEncryptedPassword: returns string encrypted password
     returns: encrypted password
     ******************************************************************/

    inline string getEncryptedPassword() {
        return encrypted;
    }

    /******************************************************************
    setEncryptedPassword: sets encrypted to string enc
    string enc = encrypted password being passed
    returns: NO RETURN Void Function
     ******************************************************************/

    inline void setEncryptedPassword(string enc) {
        encrypted = enc;
    }

    /******************************************************************
     validatePassword: checks if password entered matches encrypted password
     string& str = unencrypted password to be encrypted to check against
     returns: bool, true if matches, else false
     ******************************************************************/

    inline bool validatePassword(const string& plain) {
        return encrypt(plain) == getEncryptedPassword();
    }
};
