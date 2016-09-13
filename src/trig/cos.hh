#ifndef __cos_h__
#define __cos_h__

#include <cmath>
#include <vector>

#include "function.hh"

namespace AutoDiff {

  class Cos : public Function {

  private:
    const Function* const f;    

  public:
    Cos() : f{new Function} {}

    Cos(const Function& f_in) : f{&f_in} {}
    
    double operator()(const double& x) const {
      return cos((*f)(x));
    }

    double deriv(const double& x) const {
      return -sin((*f)(x))*(*f).deriv(x);
    } 
    
    ~Cos() {
      
	delete f;
    }
  };
};


#endif
