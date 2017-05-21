#include "pch.h"
#include "Vigenere.h"

Vigenere::Vigenere()
{
    for (char c='A';c<='Z';c++) {

        alfabeto_.push_back(c);

    }
}

Vigenere::~Vigenere()
{}

int Vigenere::find(std::vector<char>& v, char c)
{
    int i=0;
    bool encontrado = false;

    while ( i<v.size() && !encontrado ) {

        if ( v[i] == c )
            encontrado = true;
        else
            i++;

    }
    if (encontrado)
        return i;
    else
        return -1;
}

std::wstring Vigenere::encrypt(std::wstring str, std::wstring key)
{
    std::wstring enc_str;
    for (int i=0;i<str.size();i++) {

        int pos1 = find(alfabeto_, str[i]);
        int pos2 = find(alfabeto_, key[ (i%key.size()) ]);
        if ( pos1 != -1 && pos2 != -1 ) {

            int aux = pos1 + pos2;

            if ( aux >= alfabeto_.size() )
                aux = aux % (int)alfabeto_.size();

            enc_str.push_back(alfabeto_[aux]);

        }
        if ( pos1 == -1 || pos2 == -1 ) {
            std::cout << "No se ha encontrado el caracter" << std::endl;
			enc_str.clear();
            return enc_str;
        }

    }
    return enc_str;
}

std::wstring Vigenere::decrypt(std::wstring str, std::wstring key)
{
    std::wstring dec_str;
    for (int i=0;i<str.size();i++) {

        int pos1 = find(alfabeto_, str[i]);
        int pos2 = find(alfabeto_, key[ (i%key.size()) ]);
        if ( pos1 != -1 && pos2 != -1 ) {

            int aux = pos1 - pos2;

            if ( aux >= alfabeto_.size() )
                aux = aux % (int)alfabeto_.size();

            if ( aux < 0 )
                aux = alfabeto_.size() + aux;

            dec_str.push_back(alfabeto_[aux]);

        }
        if ( pos1 == -1 || pos2 == -1 ) {
            std::cout << "No se ha encontrado el caracter" << std::endl;
            dec_str.clear();
            return dec_str;
        }

    }
    return dec_str;
}


