#ifndef __tan_h__
#define __tan_h__

#include <cmath>
#include <vector>

#include "../function.hh"

namespace AutoDiff {

  class Tan : public Function {

  private:
    const Function* const f;    

  public:
    Tan() : f{new Function} {}

    Tan(const Function& f_in) : f{&f_in} {}
    
    double operator()(const double& x) const {
      return tan((*f)(x));
    }

    double deriv(const double& x) const {
      return (*f).deriv(x)/(cos((*f)(x))*cos((*f)(x)));
    } 

    ~Tan() {
      
	delete f;
    }
  };
};


#endif
