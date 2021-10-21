/*Matias Cinera
U 6931-8506
10-29-20
lab 4
*/

#ifndef __VIGENERE_H
#define __VIGENERE_H

#include "encryption.h"
#include <iostream>
#include <fstream>
using namespace std;


class VigenereEncrypt : public EncryptedFileWriter//inherit
{
    public:
        VigenereEncrypt(const string& filename, const string& code);
        virtual string encrypt(const string&) override;
    private:
        string reading; // probably not needed
        string password;
};

class VigenereDecrypt : public EncryptedFileReader//inherit
{
    public:
        VigenereDecrypt(const string& filename, const string& code);
        virtual string decrypt(const string&) override;
    private:
        string reading; // probably not needed
        string password;
        int passwordSuffix;
};

#endif