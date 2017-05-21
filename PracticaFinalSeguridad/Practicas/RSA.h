#pragma once

#include <iostream>
#include <utility>
#include <ctime>
#include <vector>
#include <cmath>
#include <string>

#include <locale>
#include <codecvt>


const long int MAX = 2147483647;

class RSA
{
private:

    long int p;
    long int q;
    long int fi;
    long int d;
    long int n;
    long int e;
    unsigned int tam_bloque;
    std::vector<std::string> substr;
    std::vector<long int> int_substr;
    std::vector<char> alfabeto;

public:

    RSA();
    ~RSA();

    bool getData();

	Platform::String^ encrypt(std::string msj);
    std::vector <long int> decrypt(std::vector <long int> enc_msj);

	void setP(long int p);
	void setQ(long int q);
	void setD(long int d);

private:

    void codification(std::string str);
    std::pair<long int, long int> mcd(long int a, long int b);
    bool LehmanPeralta(long int x);

    std::vector<long int> generadorPrimos(long int x);

    int getIndex(char c);

};
