#include "pch.h"
#include "FiatShamir.h"


FiatShamir::FiatShamir()
{}

FiatShamir::~FiatShamir()
{}

bool FiatShamir::exchange()
{
	v = ((s * s) % N);

	bool valid = true;
	int i = 0;

	while (i < it && valid) {

		a = ((x[i] * x[i]) % N);

		if (e[i]) y = ((x[i] * s) % N);
		else y = (x[i] % N);

		// Comprobacion
		if (e[i]) {
			if (((y * y) % N) != ((a * v) % N))
				valid = false;
		}
		else {
			if (((y * y) % N) != (a % N))
				valid = false;
		}
		i++;

		if (!valid) {
			std::cout << "Error en la iteracion -" << i << "-, no se ha verficado la condicion" << std::endl;
			return valid;
		}
		else {
			std::cout << "a = " << a << ", y = " << y << ", comprobar que " << y << "² = " << a << " * " << v
				<< " mod( " << N << " ) y dar por válida la iteracion" << std::endl;
		}
	}
	return valid;
}

void FiatShamir::setP(long int p)
{
	this->p = p;
}

void FiatShamir::setQ(long int q)
{
	this->q = q;
}

void FiatShamir::setN()
{
	this->N = p * q;
}

bool FiatShamir::setS(long int s)
{
	if (mcd(s, N) == 1)
	{
		this->s = s;
		return true;
	}
	else	return false;
}

void FiatShamir::setIt(int it)
{
	if (it > 0)		this->it = it;
}

void FiatShamir::pushX(long int x)
{
	this->x.push_back(x);
}

void FiatShamir::pushE(long int e)
{
	this->e.push_back(e);
}

long FiatShamir::getN()
{
	return this->N;
}

long FiatShamir::getV()
{
	return this->v;
}

bool FiatShamir::checkX()
{
    bool menorN = true;

    int i = 0;

    while ( i < x.size() && menorN ) {

        if ( x[i] >= N ) {
            menorN = false;
        }

        i++;
    }

    return menorN;
}

long int FiatShamir::mcd(long int a, long int b)
{
    long int resto = -1;
    long int resto_anterior = -1;
    while ( resto != 0 ) {

        resto_anterior = resto;
        resto = a % b;

        long int aux;
        aux = b;
        b = resto;
        a = aux;

    }
    return resto_anterior;
}
