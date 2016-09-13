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

// Declare our static default password
const string PasswordManager::DEFAULT_PASSWORD = "abc123@@@";

/******************************************************************
 PasswordManager: stores password in encrypted
 string enc = passes the password
 returns: NO RETURN
 ******************************************************************/

PasswordManager::PasswordManager(string enc)
{
    if(enc.empty())
    {
        enc = encrypt(DEFAULT_PASSWORD);
    }

    setEncryptedPassword(enc);
}

/******************************************************************
 encrypt: uses a caesar encryption to encrypt string plain
 string& plain = unencrypted string to be encrypted
 returns: string enc
 ******************************************************************/

string PasswordManager::encrypt(const string& plain)
{
    int ascii;  //ascii value of the UNENCRYPTED char
    int caesar; //ascii value of the ENCRYPTED char
    string enc; //string to hold encrypted password

    for(auto iter = plain.begin(); iter != plain.end(); iter++)
    {
        ascii = *iter;
        caesar = (((ascii - 33) + 10) % 94) + 33;

        enc.append(1, (char)caesar);
    }

    return enc;
}

/******************************************************************
 verifyPassword: checks if string str meets requirments for password
 string& str = unencrypted password
 returns: bool, true if meets standards, else false
 ******************************************************************/

bool PasswordManager::verifyPassword(const string& str)
{
    int size = 0, totTruths = 0, upTru = 0, lowTru = 0, digTru = 0, punTru = 0;
    size = str.size();

    //size: hold unencrypted password size
    //totTruths: total truths from upTru, lowTru, digTru, punTru
    //upTru: total number of Upercase letters
    //lowTru:total number of Lowerrcase letters
    //digTru: total number of numeric digits
    //punTru: total number of symbols

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

/******************************************************************
 setNewPassword: sets new password
 string& str = passes unencrypted password
 returns: bool, false if does not meet standards, true if does and call
    to encrypt password
 ******************************************************************/

bool PasswordManager::setNewPassword(const string& str)
{
    if(!verifyPassword(str))
    {
        return false;
    }

    setEncryptedPassword(encrypt(str));

    return true;
}
