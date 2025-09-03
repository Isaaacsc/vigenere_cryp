#include <iostream>
#include <string>

using namespace std;

string encrypt(string msg, string key) {
    const unsigned int msg_len = msg.length();
    const unsigned int key_len = key.length();
    string cipher = "";

    for (unsigned int i = 0, j = 0; i < msg_len; i++, j++) {
        j = j % key_len;
        int c = msg[i] + key[j] - 32;
        if (c >= 127) c -= 95;
        char ch = c;
        cipher += ch;
    }

    return cipher;
}

string decrypt(string cipher, string key) {
    const unsigned int cipher_len = cipher.length();
    const unsigned int key_len = key.length();
    string msg = "";

    for (unsigned int i = 0, j = 0; i < cipher_len; i++, j++) {
        j = j % key_len;
        int c = cipher[i] - key[j] + 32;
        if (c < 32) c += 95;
        char ch = c;
        msg += c;
    }

    return msg;
}

int main() {
    string msg, key;

    cout << "Enter message: ";
    getline(cin, msg);
    cout << "Enter key: ";
    getline(cin, key);

    string cipher = encrypt(msg, key);
    cout << "Encrypted message: " << cipher << endl;

    string decrypted_msg = decrypt(cipher, key);
    cout << "Decrypted message: " << decrypted_msg << endl;
    return 0;
}
