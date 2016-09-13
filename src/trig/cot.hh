#ifndef __cot_h__
#define __cot_h__

#include <cmath>
#include <vector>

#include "../function.hh"

namespace AutoDiff {

  class Cot : public Function {

  private:
    const Function* const f;
    
  public:
    Cot() : f{new Function} {}

    Cot(const Function& f_in) : f{&f_in} {}
    
    double operator()(const double& x) const {
      return 1/tan((*f)(x));
    }

    double deriv(const double& x) const {
      return -(*f).deriv(x)/(sin((*f)(x))*sin((*f)(x)));
    } 

    ~Cot() {
      
	delete f;
    }
  };
};


#endif
