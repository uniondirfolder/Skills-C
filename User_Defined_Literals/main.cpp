#include <iostream>
#include <iomanip>
#include <complex>
using namespace std;


/*
* Restrictions
*	char const*, unsigned long long, long double
*	char const*,std::size_t
*	wchar_t const*,std::size_t
*	char16_t const*,std::size_t
*	char32_t const*,std::size_t
*/

//-------------------------------------------------------------
long double operator"" _kg(long double x) //must be space! ._kg 
{
	return x * 1000;
}

long double operator"" _g(long double x) 
{
	return x;
}

long double operator"" _mg(long double x)
{
	return x / 1000;
}
//-------------------------------------------------------------

//imaginary literal values
constexpr complex<double> operator"" _i(long double d) 
{
	return complex <double> {0.0, static_cast <double>(d)};
}

int main() 
{


	//---------------------------------------------------------
	long double weight = 3.6_kg;
	cout << weight << endl;
	cout << setprecision(8) << (weight + 2.3_mg) << endl;
	cout << (32.3_kg / 2.0_g) << endl;
	cout << (32.3_mg * 2.0_g) << endl;
	//---------------------------------------------------------
	cout << endl;

	complex<double> z = 3.0 + 4.0_i;
	complex<double> y = 2.3 + 5.0_i;

	cout << z + y << endl;
	cout << z * y << endl;

	getchar();
	return 0;
}