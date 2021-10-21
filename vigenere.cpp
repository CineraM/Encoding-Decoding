#include "vigenere.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

VigenereEncrypt::VigenereEncrypt(const string& filename, const string& code)
: EncryptedFileWriter(filename) //init list 
{
    string pass = code;
    for(int i = 0; i < pass.size(); i++) //upper casing the password
        if(isalpha(pass[i]))
            pass[i] = toupper(pass[i]);
    password = pass;
}

VigenereDecrypt::VigenereDecrypt(const string& filename, const string& code)
: EncryptedFileReader(filename) //init list 
{
    string pass = code;
    for(int i = 0; i < pass.size(); i++) //lower casing the password 
        if(isalpha(pass[i]))
            pass[i] = tolower(pass[i]);
    password = pass;
    passwordSuffix = 0; // sufix starts at 0 since that is the 1st
}                       // letter of the password

string VigenereEncrypt::encrypt(const string& str){
    //initializing variables for encryption
    string encr = str;
    string code = this->password; 

    for(int i = 0; i < encr.size(); i++) //uppercasing all the leters
        if(isalpha(encr[i]))             //from the file (stored in encr)
            encr[i] = toupper(encr[i]);

    char hold;
    int shift, count = 0;
    for(int i = 0; i<encr.size(); i++){
        if(count == code.size())
            count = 0;
        if(encr[i] >= 'A' && encr[i] <= 'Z' ){
            shift = code[count] - 'A';
            hold = encr[i] + shift;
            
        if(hold > 'Z')
            encr[i] = hold - 26;
        else
            encr[i] = hold;
            
        count++;
        }
    }
    return encr;
}
string VigenereDecrypt::decrypt(const string& str){
    //initializing variables for encryption
    string drc = str;
    string code = this->password;

        for(int i = 0; i < drc.size(); i++)//lowercasing all the 
        if(isalpha(drc[i]))                // letters fromt he file
            drc[i] = tolower(drc[i]);
            
    char hold;
    int shift, count = this->passwordSuffix;
    for(int i = 0; i<drc.size(); i++){
        if(count == code.size())
            count = 0;

        if(drc[i] >= 'a' && drc[i] <= 'z'){
            shift = code[count] - 'a';
            hold = drc[i] - shift;

        if(hold < 'a')
            drc[i] = hold + 26;
        else
            drc[i] = hold;

        count++;
        } 
    }
    this->passwordSuffix = count;
    return drc;
}
/*
the passSuffix should equal count, since the driver
file is scanning word by word, thus calling the decription function
multiple times. If the suffix is not stored, the password suffix would 
reset each time the function is called
*/