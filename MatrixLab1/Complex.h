#pragma once
#include <string>
class Complex
{
private:
	int realCoef;
	int imaginaryCoef;
public:
	void setRealCoef(int newRealCoef);
	int getRealCoef();
	void setImaginaryCoef(int newImaginaryCoef);
	int getImaginaryCoef();
	Complex operator+ (Complex cmplx);
	Complex operator- (Complex cmplx);
	Complex operator* (Complex cmplx);
	//Complex operator= (Complex cmplx);
	//Complex operator/ (Complex cmplx);
	//Complex operator= (Complex cmplx);
	
	std::string toString();
	Complex();
	Complex(int newRealCoef, int newImaginaryCoef);
	~Complex();
};

