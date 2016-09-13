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

static const string DEFAULT_PASSWORD = "abc123@@@";

class PasswordManager
{
private:
    string encrypt(const string&);
    bool verifyPassword(const string&);
    
public:
    string encrypted;
    
    PasswordManager();
    PasswordManager(string);
    void setEncryptedPassword(string);
    bool setNewPassword(const string&);
    bool validatePassword(const string&);
    string getEncryptedPassword();
};