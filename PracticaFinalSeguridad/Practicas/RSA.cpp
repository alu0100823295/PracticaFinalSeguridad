#include "pch.h"
#include "RSA.h"

std::string make_string(const std::wstring& wstring)
{
	auto wideData = wstring.c_str();
	int bufferSize = WideCharToMultiByte(CP_UTF8, 0, wideData, -1, nullptr, 0, NULL, NULL);
	auto utf8 = std::make_unique<char[]>(bufferSize);
	if (0 == WideCharToMultiByte(CP_UTF8, 0, wideData, -1, utf8.get(), bufferSize, NULL, NULL))
		throw std::exception("Can't convert string to UTF8");

	return std::string(utf8.get());
}

/** ##########  Algoritmo Exponienciacion Rapida  ########## **/
long int exp(long int base, long int exp, long int mod){

    long int x = 1;
    long int y =  base%mod;

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
/** ##########  ##############################  ########## **/

RSA::RSA()
{
    for ( char c = 'A'; c <= 'Z'; c++ )
        alfabeto.push_back(c);
}

RSA::~RSA()
{}

bool RSA::getData()
{
    if ( LehmanPeralta(p) && LehmanPeralta(q) ) {

        n = p * q;
        fi = (p - 1) * (q - 1);

        std::pair<long int, long int> inv = mcd(d, fi);

        // Comprobacion d primo con fi y obtener inverso de d(mod n)
		if (inv.first == 1) {
			e = inv.second;
			return true;
		}
		else    return false;

    }
	else    return false;
}

std::pair<long int, long int> RSA::mcd(long int a, long int b)
{
    if ( a < b )    std::swap(a, b);

    std::vector<long int> x;
    std::vector<long int> z;

    x.push_back(a);
    x.push_back(b);

    z.push_back(0);
    z.push_back(1);

    long int resto = 1;
    int i = 1;

    while ( resto != 0 ) {

        resto = x[i-1] % x[i];
        x.push_back( resto );
        z.push_back( ( (-(x[i-1] / x[i])) * z[i] ) + z[i-1] );
        i++;
    }

    long int z_aux;

    if ( *(z.end()-2) < 0 )
        z_aux = *(z.end()-2) + fi;

    else
        z_aux = *(z.end()-2);

    return std::pair<long, long>(*(x.end()-2), z_aux);
}

Platform::String^ RSA::encrypt(std::string msj)
{
    codification(msj);

    std::vector<long int> res;

    for ( int i = 0; i < int_substr.size(); ++i )
        res.push_back( exp(int_substr[i], e, n) );


	std::string aux;

	aux += "--- DATOS ---\n";
	aux += "p = " + make_string(p.ToString()->Data()) + "         " + "q = " + make_string(q.ToString()->Data()) + "\n";
	aux += "d = " + make_string(d.ToString()->Data()) + "         " + "Φ = " + make_string(fi.ToString()->Data()) + "\n";
	aux += "e = " + make_string(e.ToString()->Data()) + "\n";
	aux += "Cadena: " + msj + "\n";
	aux += "Tamaño de bloque: " + make_string(tam_bloque.ToString()->Data()) + "\n";
	aux += "Cadena codificada numericamente: ";


    for ( auto &i: int_substr )
		aux += make_string(i.ToString()->Data()) + " ";
    aux += "\n";

    std::cout << "Cadena cifrada: ";
    for ( auto &i: res )
		aux += make_string(i.ToString()->Data()) + " ";
	aux += "\n";

	// Paso de std::string a std::wstring
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring wide = converter.from_bytes(aux);

	return ref new Platform::String(wide.c_str());
}

std::vector<long int> RSA::decrypt(std::vector<long int> enc_msj)
{
    std::vector<long int> res;

    for ( int i = 0; i < enc_msj.size(); ++i )
        res.push_back( exp(enc_msj[i], d, n) );


    std::cout << "Cadena cifrada: ";
    for ( auto &i: enc_msj )
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "Cadena descifrada codificada: ";
    for ( auto &i: res )
        std::cout << i << " ";
    std::cout << std::endl;

    return res;

}

void RSA::setP(long int p)
{
	this->p = p;
}

void RSA::setQ(long int q)
{
	this->q = q;
}

void RSA::setD(long int d)
{
	this->d = d;
}

void RSA::codification(std::string str)
{
    tam_bloque = ( log(n) / log(alfabeto.size() ) );

    int pos = str.find(' ');

    while ( pos != std::string::npos ) {

        str.erase(pos, 1);
        pos = str.find(' ');
    }

    while ( !str.empty() ) {

        substr.push_back( str.substr(0, tam_bloque) );
        str.erase(0, tam_bloque);

    }
	/*
    for ( auto &i: substr )
        std::cout << i << "##";
	*/

    for ( int i = 0; i < substr.size(); ++i ) {

        long int aux = 0;

        for ( int j = 0; j < substr[i].size(); ++j )

            aux += getIndex(substr[i][j]) * exp(alfabeto.size(),
                                                tam_bloque - (j + 1),
                                                MAX);

        int_substr.push_back(aux);
    }
}

bool RSA::LehmanPeralta(long int x)
{
    /*********************************************************** Generacion de numero primos **/
    std::vector<long int> primos = generadorPrimos(x);

    /** Comprobacion de numeros primos pequeños **/
    int i = 0;
    while ( i < primos.size() ) {

        if ( x % primos[i] == 0 ) return false;
        ++i;
    }

    /** Generacion de numeros aleatorios **/
    srand(time(NULL));
    std::vector<long int> a;
    for ( int k = 0; k < 100; ++k )
        a.push_back( rand() % (x-1) + 1 );

    /** Comprobacion de resultados de exponienciacion rapida **/
    std::vector<int> r;

    for ( int j = 0; j < a.size(); ++j ) {

        r.push_back(exp(a[j], (x-1)/2, x));
        if ( r[j] != 1 && r[j] != x-1 )  return false;
    }

    for ( int j = 0; j < r.size(); ++j )
        if ( r[j] == x-1 )   return true;

    // ToDo: Se puede mejorar la condicion de arriba
    // Se puede contar el nº de 1 en el primer for y dps comprobar con el tamaño del vector r

    return false;
}

std::vector<long int> RSA::generadorPrimos(long int x)
{
    std::vector<long int> primos;
    primos.push_back(2);

    long int n_primos;

    if ( x < MAX/10000 )
        n_primos = (x/2) + (x/3);

    else
        n_primos = x/1000;

    for ( long int i = 3; i <= n_primos; i=i+2 ) {

        bool isPrimo = true;
        int j = i - 1;

        while ( j > 1 && isPrimo ) {

            if ( i % j == 0 )   isPrimo = false;

            --j;
        }
        if ( isPrimo )  primos.push_back(i);
    }

    return primos;
}

int RSA::getIndex(char c)
{
    for ( int i = 0; i < alfabeto.size(); ++i )

        if ( alfabeto[i] == c )     return i;

    return -1;
}
