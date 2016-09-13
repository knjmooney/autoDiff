#ifndef __sinh_h__
#define __sinh_h__

#include <cmath>

#include "function.hh"

namespace AutoDiff {

  class Sinh : public Function {

  private:
    const Function* const f;    

  public:
    Sinh() : f{new Function} {}

    Sinh(const Function& f_in) : f{&f_in} {}
    
    double operator()(const double& x) const {
      return sinh((*f)(x));
    }

    double deriv(const double& x) const {
      return cosh((*f)(x))*(*f).deriv(x);
    } 

    ~Sinh() {
      
	delete f;
    }
  };
};


#endif
