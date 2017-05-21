#include "pch.h"
#include "DiffieHellman.h"

/** Algoritmo Exponenciacion Rapida **/

int exponentiation(int base, int exp, int mod){

    int x = 1;
    int y =  base%mod;

    while ( exp > 0 && y > 1 ) {
        if ( exp%2 == 1 ) {

            x = (x*y)%mod;
            exp--;

        }
        else {

            y = (y*y)%mod;
            exp = exp/2;

        }

    }
    return x;
}
/** ******************************* **/


DiffieHellman::DiffieHellman() :
        p_(0),
        alpha_(0),
        xa_(0),
        xb_(0),
        ya_(0),
        yb_(0),
        ka_(0),
        kb_(0)
{}

DiffieHellman::DiffieHellman(int p, int alpha, int xa, int xb) :
        p_(p),
        alpha_(alpha),
        xa_(xa),
        xb_(xb)
{}

int DiffieHellman::generate()
{
    ya_ = exponentiation(alpha_, xa_, p_);
    yb_ = exponentiation(alpha_, xb_, p_);

    ka_ = exponentiation(yb_, xa_, p_);
    kb_ = exponentiation(ya_, xb_, p_);

    if ( ka_ == kb_ )   return ka_;

    else    return -1;
}

bool DiffieHellman::setP(int p)
{
	if (isPrimo(p)) {
		p_ = p;
		return true;
	}
	else {
		return false;
	}
}

bool DiffieHellman::setAlpha(int alpha)
{
	if (alpha < p_) {
		alpha_ = alpha;
		return true;
	}
	else	return false;
}

void DiffieHellman::setXa(int xa)
{
	xa_ = xa;
}

void DiffieHellman::setXb(int xb)
{
	xb_ = xb;
}

int DiffieHellman::getYa()
{
	return ya_;
}

int DiffieHellman::getYb()
{
	return yb_;
}

bool DiffieHellman::isPrimo(int x)
{
	bool isPrimo = true;
	int aux = x - 1;

	while (aux > 1 && isPrimo) {

		if (x%aux == 0)
			isPrimo = false;

		aux--;

	}
	return isPrimo;
}
