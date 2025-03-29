#include <iostream>
#include <string>

using namespace std;

string encrypt(string input, string key) {
    string output = "";
    unsigned int key_length = key.length();
    unsigned int i = 0;

    for (unsigned char ch : input) {
        unsigned char asc_key = key[i % key_length];
        
        unsigned char shift = asc_key - 32;
        unsigned char new_val = 32 + ((ch - 32 + shift) % 95);
        
        output += static_cast<char>(new_val);
        i++;
    }
    return output;
}

string decrypt(string output, string key) {
    string input = "";
    unsigned int key_length = key.length();
    unsigned int i = 0;

    for (unsigned char ch : output) {
        unsigned char asc_key = key[i % key_length];
        
        unsigned char shift = asc_key - 32;
        unsigned char new_val = 32 + ((ch - 32 + 95 - shift) % 95);
        
        input += static_cast<char>(new_val);
        i++;
    }
    return input;
}

int main() {
    string key, input, output, dec_output;

    cout << "Enter key: ";
    getline(cin, key);

    cout << "Enter message: ";
    getline(cin, input);

    output = encrypt(input, key);
    cout << "Encrypted: " << output << endl;

    dec_output = decrypt(output, key);
    cout << "Decrypted: " << dec_output << endl;

    if (input == dec_output) {
        cout << "The encryption was successful!" << endl;
    } else {
        cout << "The encryption wasn't successful!" << endl;
    }

    return 0;
}