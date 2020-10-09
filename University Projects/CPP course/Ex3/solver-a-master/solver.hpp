using namespace std;
#include <complex>
#include <iostream>

namespace solver {

class RealVariable{
    public: 
    double x,x2,c;
    RealVariable(): x2(0), x(1), c(0) {}
    RealVariable(double x2 ,double x, double c){
        this->x2=x2;
        this->x=x;
        this->c=c;
    }
 

	//operator +
friend RealVariable operator+(const double num,const RealVariable& v1);
//friend RealVariable operator+(const int num,const RealVariable& v1);
//friend RealVariable operator+(const RealVariable& v1,const int num);
friend RealVariable operator+(const RealVariable& v1,const double num);
friend RealVariable operator+(const RealVariable& v1,const RealVariable& v2);
	//operator -
friend RealVariable operator-(const double num,const RealVariable& v1);
//friend RealVariable operator-(const int num,const RealVariable& v1);
//friend RealVariable operator-(const RealVariable& v1,const int num);
friend RealVariable operator-(const RealVariable& v1,const double num);
friend RealVariable operator-(const RealVariable& v1,const RealVariable& v2);
	//operator *
friend RealVariable operator*(const double num,const RealVariable& v1);
//friend RealVariable operator*(const int num,const RealVariable& v1);
//friend RealVariable operator*(const RealVariable& v1,const int num);
friend RealVariable operator*(const RealVariable& v1,const double num);
friend RealVariable operator*(const RealVariable& v1,const RealVariable& v2);
	//operator /
friend RealVariable operator/(const double num,const RealVariable& v1);
//friend RealVariable operator/(const int num,const RealVariable& v1);
//friend RealVariable operator/(const RealVariable& v1,const int num);
friend RealVariable operator/(const RealVariable& v1,const double num);
friend RealVariable operator/(const RealVariable& v1,const RealVariable& v2);
	//operator ^
friend RealVariable operator^(const RealVariable& v1,const double num);
	//operator ==
//friend RealVariable operator==(const int num,const RealVariable& v1);
friend RealVariable operator==(const double num,const RealVariable& v1);
//friend RealVariable operator==(const RealVariable& v1,const int num);
friend RealVariable operator==(const RealVariable& v1,const double num);
friend RealVariable operator==(const RealVariable& v1,const RealVariable& v2);
};


class ComplexVariable{
    public:
    complex<double> x,x2,c;
    ComplexVariable(): x2(0), x(1), c(0) {}
    ComplexVariable(complex<double> x2 ,complex<double> x, complex<double> c){
        this->x2=complex<double>(x2);
        this->x=complex<double>(x);
        this->c=complex<double>(c);
    }
	//operator +
friend ComplexVariable operator+(const complex<double> num,const ComplexVariable& v1);
friend ComplexVariable operator+(const ComplexVariable& v1,const complex<double> num);
friend ComplexVariable operator+(const ComplexVariable& v1,const ComplexVariable& v2);
	//operator -
friend ComplexVariable operator-(const complex<double> num,const ComplexVariable& v1);
friend ComplexVariable operator-(const ComplexVariable& v1,const complex<double> num);
friend ComplexVariable operator-(const ComplexVariable& v1,const ComplexVariable& v2);
	//operator *
friend ComplexVariable operator*(const complex<double> num,const ComplexVariable& v1);
friend ComplexVariable operator*(const ComplexVariable& v1,const complex<double> num);
friend ComplexVariable operator*(const ComplexVariable& v1,const ComplexVariable& v2);
	//operator /
friend ComplexVariable operator/(const complex<double> num,const ComplexVariable& v1);
friend ComplexVariable operator/(const ComplexVariable& v1,const complex<double> num);
friend ComplexVariable operator/(const ComplexVariable& v1,const ComplexVariable& v2);
	//operator ^
friend ComplexVariable operator^(const complex<double> num,const ComplexVariable& v1);
friend ComplexVariable operator^(const ComplexVariable& v1,const complex<double> num);
friend ComplexVariable operator^(const ComplexVariable& v1,const ComplexVariable& v2);
	//operator ==
friend ComplexVariable operator==(const complex<double> num,const ComplexVariable& v1);
friend ComplexVariable operator==(const ComplexVariable& v1,const complex<double> num);
friend ComplexVariable operator==(const ComplexVariable& v1,const ComplexVariable& v2);
};
double solve (const RealVariable& v1);
complex<double> solve (const ComplexVariable & v1);
}

