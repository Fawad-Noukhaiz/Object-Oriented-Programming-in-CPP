#include <bits/stdc++.h>

using namespace std;

string encrypt(const string& text) {
    string encrypted = "";
    for (int i = 0; i < text.length(); i++) {
        encrypted += char(int(text[i]) + (i + 1));
    }
    return encrypted;
}

string decrypt(const string& text) {
    string decrypted = "";
    for (int i = 0; i < text.length(); i++) {
        decrypted += char(int(text[i]) - (i + 1));
    }
    return decrypted;
}

int main() {
    string input, encryptedText, decryptedText;
    cout << "Enter String: ";
    getline(cin, input);

    encryptedText = encrypt(input);

    ofstream outFile("encrypted.txt");
    outFile << encryptedText;
    outFile.close();

    cout << "Normal Text:= " << input << endl;
    cout << "Encrypted text inserted in file" << endl;

    ifstream inFile("encrypted.txt");
    string fileContent((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    decryptedText = decrypt(fileContent);

    cout << "Decrypted text Read then decoded from file" << endl;
    cout << decryptedText << endl;

    return 0;
}
