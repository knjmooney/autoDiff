#ifndef __sin_h__
#define __sin_h__

#include <cmath>
#include <vector>

#include "../function.hh"

namespace AutoDiff {

  class Sin : public Function {

  private:
    const Function* const f;   

  public:
    Sin() : f{new Function} {}

    Sin(const Function& f_in) : f{&f_in} {}
    
    double operator()(const double& x) const {
      return sin((*f)(x));
    }

    double deriv(const double& x) const {
      return cos((*f)(x))*(*f).deriv(x);
    } 

    ~Sin() {
      
	delete f;
    }
  };
};


#endif
