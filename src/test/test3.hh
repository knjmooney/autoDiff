#ifndef __test3_h__
#define __test3_h__

#include <cmath>

#include "../function.hh"

namespace AutoDiff {

  class Test3 : public Function {

  public:
    double operator()(const double& x) const {
      return exp(pow(x,2.5)) / ( log(x) + 1/tanh(x) );
    }

    double deriv(const double& x) const {
      return ( ( 2.5 * exp( pow(x,2.5) ) * pow(x,1.5) ) / ( log(x) + 1 / tanh(x) )
	       - ( exp ( pow(x,2.5) ) * ( ( 1 / x ) - ( 1 / pow( sinh(x), 2 ) ) ) ) / pow( log(x) + 1 / tanh(x), 2) );
    } 
  };
};


#endif
