#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>
using namespace std;
int main ()
{
    CryptoPP::SHA256 hash;


    string msg = "";
    string stroka;
    ifstream f("/home/guffindor/test/msg");
    while (getline(f, stroka)) {
        msg += stroka;
    }

    vector<byte> digest(hash.DigestSize());

    hash.Update((const byte*)msg.data(), msg.size());
    hash.Final(digest.data());

    cout << "Сообщение: " << msg << endl;

    cout << "Результат хэш-функции ";
    CryptoPP::StringSource(digest.data(), digest.size(), true, new CryptoPP::HexEncoder(new CryptoPP::FileSink(cout)));
    cout << endl;
    return 0;
}
