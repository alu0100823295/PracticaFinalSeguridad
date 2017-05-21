#pragma once

#include <iostream>

class DiffieHellman
{

private:

    int p_;
    int alpha_;
    int xa_;
    int xb_;
    int ya_;
    int yb_;
    int ka_;
    int kb_;

public:

    DiffieHellman();
    DiffieHellman(int p, int alpha, int xa, int xb);
    int generate();

	bool setP(int p);
	bool setAlpha(int alpha);
	void setXa(int xa);
	void setXb(int xb);

	int getYa();
	int getYb();


private:

    bool isPrimo(int x);

};
