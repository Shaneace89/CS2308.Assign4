#include <fstream>
#include <string>

#include "PasswordManager.h"

using namespace std;

PasswordManager::PasswordManager() : password(""), encrypted("") { }

PasswordManager::PasswordManager(string enc) {
    if(enc.empty()) {
        encrypted = encrypt(DEFAULT_PASSWORD);
    } else {
        encrypted = enc;
    }
}

string PasswordManager::encrypt(const string& plain) {
    int ascii;
    int caesar;
    string enc;
    
    for(auto iter = plain.begin(); iter != plain.end(); ++iter) {
        ascii = (int)*iter;
        caesar = (((ascii - 33) + 10) % 94) + 33;
        
        enc.append(1, (char)caesar);
    }
    
    return enc;
}

bool PasswordManager::verifyPassword(const string& str)
{
    int size = 0, truths = 0;
    size = str.size();
    
    if (size >= 8)
    {
        for (int i = 0 ; i < size ; ++i)
            if (isupper(str[i]))
                truths++;
        
            else if (islower(str[i]))
                truths++;
        
            else if (isdigit(str[i]))
                truths++;
        
            else if (ispunct(str[i]))
                truths++;
        
        if (truths >= 3)
            return true;
    }
    else
        return false;
}

void PasswordManager::setEncryptedPassword(string enc) {
    encrypted = enc;
}

string PasswordManager::getEncryptedPassword() {
    return encrypted;
}

bool PasswordManager::setNewPassword(const string& str) {
    if(!verifyPassword(str))
    {
        cout << "Password entered does not meet standards." << endl;
        return false;
    }
    
    else
    setEncryptedPassword(encrypt(str));
    
    return true;
}

bool PasswordManager::validatePassword(const string& str) {
    return encrypt(str) == getEncryptedPassword();
}