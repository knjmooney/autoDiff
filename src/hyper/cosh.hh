#ifndef __cosh_h__
#define __cosh_h__

#include <cmath>

#include "function.hh"

namespace AutoDiff {

  class Cosh : public Function {

  private:
    const Function* const f;    

  public:
    Cosh() : f{new Function} {}

    Cosh(const Function& f_in) : f{&f_in} {}
    
    double operator()(const double& x) const {
      return cosh((*f)(x));
    }

    double deriv(const double& x) const {
      return sinh((*f)(x))*(*f).deriv(x);
    } 

    ~Cosh() {
      
	delete f;
    }
  };
};


#endif
