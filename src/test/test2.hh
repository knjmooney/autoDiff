#ifndef __test2_h__
#define __test2_h__

#include <cmath>

#include "../function.hh"

namespace AutoDiff {

  class Test2 : public Function {

  public:
    double operator()(const double& x) const {
      return tan(x*x + 2*x + 1);
    }

    double deriv(const double& x) const {
      return ( 2*x + 2 ) / ( cos(x*x + 2*x + 1) * cos(x*x + 2*x + 1) );
    } 

  };
};


#endif
