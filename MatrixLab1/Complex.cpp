#include "Complex.h"

void Complex::setRealCoef(int newRealCoef)
{
	realCoef = newRealCoef;
};
int Complex::getRealCoef()
{
	return realCoef;
};

void Complex::setImaginaryCoef(int newImaginaryCoef)
{
	imaginaryCoef = newImaginaryCoef;
};
int Complex::getImaginaryCoef()
{
	return imaginaryCoef;
};



Complex Complex::operator+ (Complex cmplx) 
{
	return Complex(realCoef + cmplx.realCoef, imaginaryCoef + cmplx.imaginaryCoef);
}
Complex Complex::operator- (Complex cmplx)
{
	return Complex(realCoef - cmplx.realCoef, imaginaryCoef - cmplx.imaginaryCoef);
};
Complex Complex::operator* (Complex cmplx)
{
	int newRealCoef = realCoef*cmplx.realCoef - imaginaryCoef*cmplx.imaginaryCoef;
	int newImaginaryCoef = realCoef*cmplx.imaginaryCoef + imaginaryCoef*cmplx.realCoef;
	return Complex(newRealCoef, newImaginaryCoef);
};

std::string Complex:: toString() 
{
	std::string resultStr;
	if (imaginaryCoef > 0)
		resultStr = "(" + std::to_string(realCoef) + " + " + std::to_string(imaginaryCoef) + "i)" ;
	if (imaginaryCoef == 0)
		resultStr = "(" + std::to_string(realCoef) + ")";
	if (imaginaryCoef < 0)
		resultStr = "(" + std::to_string(realCoef) + " - " + std::to_string(-imaginaryCoef) + "i)";
	return resultStr;
}
Complex::Complex()
{
	realCoef = 0;
	imaginaryCoef = 0;
}

Complex::Complex(int newRealCoef, int newImaginaryCoef)
{
	realCoef = newRealCoef;
	imaginaryCoef = newImaginaryCoef;
}

Complex::~Complex()
{
}
