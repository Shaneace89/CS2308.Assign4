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

bool PasswordManager::verifyPassword(const string& str) {
    // password meets specs
  return true;
}

void PasswordManager::setEncryptedPassword(string enc) {
  encrypted = enc;
}

string PasswordManager::getEncryptedPassword() {
  return encrypted;
}

bool PasswordManager::setNewPassword(const string& str) {
  if(!verifyPassword(str)) {
    return false;
  }

  setEncryptedPassword(encrypt(str));

  return true;
}

bool PasswordManager::validatePassword(const string& str) {
  return encrypt(str) == getEncryptedPassword();
}