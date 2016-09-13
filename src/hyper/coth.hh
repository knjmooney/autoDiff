#ifndef __coth_h__
#define __coth_h__

#include <cmath>

#include "function.hh"

namespace AutoDiff {

  class Coth : public Function {

  private:
    const Function* const f;    

  public:
    Coth() : f{new Function} {}

    Coth(const Function& f_in) : f{&f_in} {}
    
    double operator()(const double& x) const {
      return 1/tanh((*f)(x));
    }

    double deriv(const double& x) const {
      return -(*f).deriv(x)/(sinh((*f)(x))*sinh((*f)(x)));
    } 

    ~Coth() {
      
	delete f;
    }
  };
};


#endif
