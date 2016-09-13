#ifndef __tanh_h__
#define __tanh_h__

#include <cmath>

#include "function.hh"

namespace AutoDiff {

  class Tanh : public Function {

  private:
    const Function* const f;
    
  public:
    Tanh() : f{new Function} {}

    Tanh(const Function& f_in) : f{&f_in} {}
    
    double operator()(const double& x) const {
      return tanh((*f)(x));
    }

    double deriv(const double& x) const {
      return (*f).deriv(x)/(cosh((*f)(x))*cosh((*f)(x)));
    } 

    ~Tanh() {
      
	delete f;
    }
  };
};


#endif
