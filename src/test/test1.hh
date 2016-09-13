#ifndef __test1_h__
#define __test1_h__

#include <cmath>

#include "../function.hh"

namespace AutoDiff {

  class Test1 : public Function {

  public:
    double operator()(const double& x) const {
      return sin(x);
    }

    double deriv(const double& x) const {
      return cos(x);
    } 
  };
};


#endif
