#ifndef __test4_h__
#define __test4_h__

#include <cmath>

#include "../function.hh"

namespace AutoDiff {

  class Test4 : public Function {

  public:
    double operator()(const double& x) const {
      return 5 * tan ( pow(x,2.5) ) / ( pow(x,3) + 25*x + 9 );
    }

    double deriv(const double& x) const {
      return ( ( 12.5 * pow(x,1.5) * pow( 1 / cos ( pow (x,2.5) ), 2 ) ) / ( x*x*x + 25 * x + 9 )
	       - ( 5 * ( 3 * x*x + 25 ) * tan ( pow(x,2.5) ) ) / pow ( ( x*x*x + 25 * x + 9 ), 2 ) );
    } 
  };
};


#endif
