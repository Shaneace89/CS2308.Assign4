#include <iostream>
#include <string>

using namespace std;

static const string DEFAULT_PASSWORD = "abc123@@@";

class PasswordManager
{
private:
    string password;
    
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