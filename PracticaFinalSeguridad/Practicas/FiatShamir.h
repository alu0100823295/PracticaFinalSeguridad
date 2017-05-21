#pragma once

#include <iostream>
#include <vector>

#include "..\FiatShamirUserControl.xaml.h"

using namespace PracticaFinalSeguridad;

class FiatShamir
{

private:
    long int p;
    long int q;
    long int N;
    long int s;
    long int v;
    std::vector<long int> x;
    std::vector<bool> e;
    long int a;
    long int y;
    int it;

public:

    FiatShamir();
    ~FiatShamir();

    bool exchange(); // Pasar por referencia Textbox para modificar la salida

	void setP(long int p);
	void setQ(long int q);
	void setN();
	bool setS(long int s);
	void setIt(int it);

	void pushX(long int x);
	void pushE(long int e);

	long getN();
	long getV();

private:

    bool checkX();
    long int mcd(long int a, long int b);

};
