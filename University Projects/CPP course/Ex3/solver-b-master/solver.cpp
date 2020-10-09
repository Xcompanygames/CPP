#include <iostream>
#include <complex>
#include <math.h> 
#include "solver.hpp"
using namespace std;
	namespace solver{

	////////////////////////Operator +
    	RealVariable operator+(double num,const RealVariable& v1){
          return RealVariable(v1.x2,v1.x,v1.c+num);
    }
    	RealVariable operator+(const RealVariable& v1,double num){
          return RealVariable(v1.x2,v1.x,v1.c+num);
    }
    	RealVariable operator+(const RealVariable& v1,const RealVariable& v2){
          return RealVariable(v1.x2+v2.x2,v1.x+v2.x,v1.c+v2.c);
    }

	////////////////////////Operator - 
	    RealVariable operator-(const double num,const RealVariable& v1){
          return RealVariable(v1.x2,v1.x,num-v1.c);
    }
	    RealVariable operator-(const RealVariable& v1,const double num){
          return RealVariable(v1.x2,v1.x,v1.c-num);
    }
      	RealVariable operator-(const RealVariable& v1,const RealVariable& v2){
          return RealVariable(v1.x2-v2.x2,v1.x-v2.x,v1.c-v2.c);
    }

	////////////////////////Operator *
		RealVariable operator*(double num,const RealVariable& v1){
          return RealVariable(v1.x2*num,v1.x*num,v1.c*num);
    }	
		RealVariable operator*(const RealVariable& v1,double num){
          return RealVariable(v1.x2*num,v1.x*num,v1.c*num);
    }
    	RealVariable operator*(const RealVariable& v1,const RealVariable& v2){
          return RealVariable(v1.x2*v2.c+v1.c*v2.x2+v1.x*v2.x,v1.c*v2.x+v1.x*v2.c,v1.c*v2.c);
    }

	
	////////////////////////Operator ==
      	RealVariable operator==(const RealVariable& v1,const RealVariable& v2){
          return RealVariable(v2-v1);
    }
      	RealVariable operator==(const double num,const RealVariable& v1){
          return RealVariable(v1-num);
    }
      	RealVariable operator==(const RealVariable& v1,const double num){
          return RealVariable(v1-num);
    }


	////////////////////////Operator ^ 
	    RealVariable operator^(const RealVariable& v1,const double num){
              if(num==0)return RealVariable(0,0,1);
		  if(num==1)return v1;
		  if(num==2){
			//RealVariable is without X or X^2
			if(v1.x2==0&&v1.x==0&&v1.c!=0){
				return RealVariable(0,0,pow(v1.c,2));
			}
			//RealVariable is without X^2 or C
			else if(v1.x2==0&&v1.x!=0&&v1.c==0){
				return RealVariable(v1.x,0,0);
			}
			//RealVariable is without X2
			else if(v1.x2==0&&v1.x!=0&&v1.c!=0){
				return RealVariable(1,v1.x*num*v1.c,v1.c*v1.c);
			}
			//RealVariable is without X^2 or C
			else{
		throw runtime_error {"Can't do that"};
			}                  		
		  }

              //C is alone
		  if(v1.x2==0&&v1.x==0&&v1.c!=0){
		 	return RealVariable(0,0,pow(v1.c,num));
		  }

			throw runtime_error {"Can't do that"};
      }



	/////////////////////////////////////////////

	////////////////////////Operator /
		RealVariable operator/(double num,const RealVariable& v1){
            if(v1.x2==0&&v1.x==0&& v1.c==0)throw runtime_error {"CAN'T DIVIDE BY ZERO"};
          return RealVariable(num/v1.x2,num/v1.x,num/v1.c);
    }	
		RealVariable operator/(const RealVariable& v1,double num){
            if(num==0)throw runtime_error {"CAN'T DIVIDE BY ZERO"};
          return RealVariable(v1.x2*(1/num),v1.x*(1/num),v1.c*(1/num));
    }
    	RealVariable operator/(const RealVariable& v1,const RealVariable& v2){
            if(v2.x2==0&&v2.x==0&& v2.c==0)throw runtime_error {"CAN'T DIVIDE BY ZERO"};
          return RealVariable(v1.x2/v2.x2,v1.x/v2.x,v1.c/v2.c);

    }
	//////////////Complex Number//////////////
	////////////////////////Operator +
    	ComplexVariable operator+(complex<double>  num,const ComplexVariable& v1){
          return ComplexVariable(v1.x2,v1.x,v1.c+num);
    }
    	ComplexVariable operator+(const ComplexVariable& v1,complex<double> num){
          return ComplexVariable(v1.x2,v1.x,v1.c+num);
    }
    	ComplexVariable operator+(const ComplexVariable& v1,const ComplexVariable& v2){
          return ComplexVariable(v1.x2+v2.x2,v1.x+v2.x,v1.c+v2.c);
    }

	////////////////////////Operator - 
	    ComplexVariable operator-(const complex<double>  num,const ComplexVariable& v1){
          return ComplexVariable(v1.x2,v1.x,num-v1.c);
    }
	    ComplexVariable operator-(const ComplexVariable& v1,const complex<double> num){
          return ComplexVariable(v1.x2,v1.x,v1.c-num);
    }
      	ComplexVariable operator-(const ComplexVariable& v1,const ComplexVariable& v2){
          return ComplexVariable(v1.x2-v2.x2,v1.x-v2.x,v1.c-v2.c);
    }

	////////////////////////Operator *
		ComplexVariable operator*(complex<double> num,const ComplexVariable& v1){
          return ComplexVariable(v1.x2*num,v1.x*num,v1.c*num);
    }	
		ComplexVariable operator*(const ComplexVariable& v1,complex<double> num){
          return ComplexVariable(v1.x2*num,v1.x*num,v1.c*num);
    }
    	ComplexVariable operator*(const ComplexVariable& v1,const ComplexVariable& v2){
          return ComplexVariable(v1.x2*v2.x2+v1.x2*v2.x2+v1.x2*v2.c
		  ,v1.x*v2.x+v1.x*v2.x2+v1.x*v2.c
		  ,v1.c*v2.c+v1.c*v2.x2+v1.c*v2.x);
    }
	
	////////////////////////Operator ==
      	ComplexVariable operator==(const ComplexVariable& v1,const ComplexVariable& v2){
          return ComplexVariable(v1-v2);
    }
      	ComplexVariable operator==(const complex<double> num,const ComplexVariable& v1){
          return ComplexVariable(v1-num);
    }
      	ComplexVariable operator==(const ComplexVariable& v1,const complex<double> num){
          return ComplexVariable(v1-num);
    }


	////////////////////////Operator ^ 
        ComplexVariable operator^(const ComplexVariable &v1, const complex<double> num){
         if(num ==complex<double>(0.0,0.0))
          return ComplexVariable(0,0,1);
         if(num ==complex<double>(1.0,0.0))
          return v1;
         if(num ==complex<double>(2.0,0.0) && v1.x2==complex<double>(0.0,0.0) && v1.x!=complex<double>(0.0,0.0) && v1.c!=complex<double>(0.0,0.0))
          return ComplexVariable(1,v1.x*num*v1.c,v1.c*v1.c);
         if(num ==complex<double>(2.0,0.0) && v1.x2==complex<double>(0.0,0.0) && v1.x==complex<double>(0.0,0.0) && v1.c!=complex<double>(0.0,0.0)) 
          return ComplexVariable(0,0,v1.c*v1.c);
         if(num ==complex<double>(2.0,0.0) && v1.x2==complex<double>(0.0,0.0) && v1.x!=complex<double>(0.0,0.0) && v1.c==complex<double>(0.0,0.0)) 
          return ComplexVariable(v1.x,0,0);
         if(num.real() >2 && v1.x2==complex<double>(0.0,0.0) && v1.x==complex<double>(0.0,0.0) && v1.c!=complex<double>(0.0,0.0)) 
          return ComplexVariable(0,0,pow(v1.c,num));

          throw runtime_error {"Can't do that, value to operator ^ is too high"};
        }
	/////////////////////////////////////////////

	////////////////////////Operator /
		ComplexVariable operator/(complex<double> num,const ComplexVariable& v1){
             if(v1.x2==0.0&&v1.x==0.0&&v1.c==0.0){
               throw runtime_error {"Can't divide by zero!"};
            }
          return ComplexVariable(num/v1.x2,num/v1.x,num/v1.c);
    }	
		ComplexVariable operator/(const ComplexVariable& v1,complex<double> num){
            if(num==0.0){
               throw runtime_error {"Can't divide by zero!"};
            }
          return ComplexVariable(v1.x2/num,v1.x/num,v1.c/num);
    }
    	ComplexVariable operator/(const ComplexVariable& v1,const ComplexVariable& v2){
          return ComplexVariable(v1.x2*v2.x2+v1.x2*v2.x2+v1.x2*v2.c
		  ,v1.x*v2.x+v1.x*v2.x2+v1.x*v2.c
		  ,v1.c*v2.c+v1.c*v2.x2+v1.c*v2.x);
    }


	//////////////////////////////////////////solvers
    double solve (const RealVariable& v1){
         double x2 = v1.x2;
         double x =  v1.x;
         double c =  v1.c;
         float discriminant = x*x - 4*x2*c;
         if(x2==0){
               return c/-x;
         }
          if(x2==0 && x==0 && c==0){
               throw runtime_error {"There isn't any solution"};
          }
         if( x2==0 && x==0 && c!=0){
               throw runtime_error {"There isn't any solution"};
          }
         if((discriminant > 0||discriminant == 0)&& x2!=0){
            return(-x + sqrt(discriminant)) / (2*x2);
         }
         else throw runtime_error {"There is only an imaginary solution"};
    }

    complex<double> solve (const ComplexVariable & v1){
         complex<double> x2 = v1.x2;
         complex<double> x =  v1.x;
         complex<double> c =  v1.c;
         complex<double> discriminant = (x*x - 4.0*x2*c);
         if(x2==complex(0.0,0.0)&&x==complex(0.0,0.0)&&c==complex(0.0,0.0)){
               throw runtime_error {"There isn't any solution"};
         }
         if(x2==complex(0.0,0.0)&&x==complex(0.0,0.0)&&c!=complex(0.0,0.0)){
               throw runtime_error {"There isn't any solution"};
         }
         if(x2==complex(0.0,0.0)){
               return c/-x;
         }
         if((discriminant.real() > 0.0||discriminant.real() == 0.0)&& x2!=complex(0.0,0.0)){
            return((-x + sqrt(discriminant)) / (2.0*x2));
         }
         else{
               return(complex(-x.real()/(2.0*x2.real()),sqrt(-discriminant.real())/(2.0*x2.real())));
         }
    }
}

