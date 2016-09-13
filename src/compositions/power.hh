#ifndef __power_h__
#define __power_h__

#include <cmath>

#include "function.hh"

namespace AutoDiff {

  class Power : public Function {

  private:
    const Function* const f;
    const double exponent;

  public:
    Power(const double& e, const Function& f_in) : f{&f_in}, exponent{e} {} 
    
    double operator()(const double& x) const {
      return pow((*f)(x),exponent);
    }

    double deriv(const double& x) const {
      return exponent * pow((*f)(x),exponent-1) * (*f).deriv(x);
    }

    ~Power() {
      delete f;
    }
  };
};


#endif
