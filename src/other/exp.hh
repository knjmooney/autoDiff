#ifndef __exp_h__
#define __exp_h__

#include <cmath>

#include "function.hh"

namespace AutoDiff {

  class Exp : public Function {

  private:
    const Function* const f;

  public:
    Exp(const Function& f_in) : f{&f_in} {} 

    Exp() : f{new Function} {}
    
    double operator()(const double& x) const {
      return exp((*f)(x));
    }
    
    double deriv(const double& x) const {
      return (*f).deriv(x)*exp((*f)(x));
    }

    ~Exp() {
      delete f;
    }
  };
};


#endif
