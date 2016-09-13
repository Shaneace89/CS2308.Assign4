/*File Name: PasswordManager.cpp
 
 Author: Shane Fleming
 Date: 03/11/16
 Assignment Number: 4
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Password Manager, Contains functions of the Class PasswordManager*/

#include <fstream>
#include <string>
#include "PasswordManager.h"

using namespace std;

PasswordManager::PasswordManager() : password(""), encrypted("") { }

PasswordManager::PasswordManager(string enc)
{
    if(enc.empty())
    {
        encrypted = encrypt(DEFAULT_PASSWORD);
    } else
    {
        encrypted = enc;
    }
}

string PasswordManager::encrypt(const string& plain)
{
    int ascii;
    int caesar;
    string enc;
    
    int size = plain.size();
    
    for(int x = 0; x < size; x++)
    {
        ascii = plain[x];
        caesar = (((ascii - 33) + 10) % 94) + 33;
        
        enc.append(1, (char)caesar);
    }
    
    return enc;
}

bool PasswordManager::verifyPassword(const string& str)
{
    int size = 0, totTruths = 0, upTru = 0, lowTru = 0, digTru = 0, punTru = 0;
    size = str.size();
    
    if (size >= 8)
    {
        for (int i = 0 ; i < size ; ++i)
        {
            if (isupper(str[i]))
                upTru++;
            
            else if (islower(str[i]))
                lowTru++;
            
            else if (isdigit(str[i]))
                digTru++;
            
            else if (ispunct(str[i]))
                punTru++;
        }
        
        if (upTru >= 1)
            totTruths++;
        if (lowTru >= 1)
            totTruths++;
        if (digTru >= 1)
            totTruths++;
        if (punTru >= 1)
            totTruths++;
        
        if (totTruths >= 3)
            return true;
        else
            return false;
    }
    else
        return false;
    
    return false;
}

void PasswordManager::setEncryptedPassword(string enc)
{
    encrypted = enc;
}

string PasswordManager::getEncryptedPassword()
{
    return encrypted;
}

bool PasswordManager::setNewPassword(const string& str)
{
    if(!verifyPassword(str))
    {
        cout << "Password entered does not meet standards." << endl;
        return false;
    }
    
    else
    {
        if (str == "abc123@@@")
            setEncryptedPassword(encrypt(str));
        else
        {
            cout << "Password changed successfully." << endl;
            setEncryptedPassword(encrypt(str));
        }
    }
    
    
    return true;
}

bool PasswordManager::validatePassword(const string& str)
{
    return encrypt(str) == getEncryptedPassword();
}