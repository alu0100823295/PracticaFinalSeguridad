#include <vector>
#include <string>
#include <iostream>

class Vigenere
{

private:

    std::vector<char> alfabeto_;


    int find(std::vector<char>& v, char c);

public:

    Vigenere();
    ~Vigenere();

    std::wstring encrypt(std::wstring str, std::wstring key);
    std::wstring decrypt(std::wstring str, std::wstring key);

};
