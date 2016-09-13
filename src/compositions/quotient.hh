#ifndef __quotient_h__
#define __quotient_h__

#include <vector>

#include "function.hh"

namespace AutoDiff {

  class Quotient : public Function {

  private:
    const Function* const f1;
    const Function* const f2;

  public:
    Quotient(const Function& f1_in, const Function& f2_in) : f1{&f1_in}, f2{&f2_in} {} 
    
    double operator()(const double& x) const {
      return (*f1)(x)/(*f2)(x);
    }

    double deriv(const double& x) const {
      return ((*f1).deriv(x)*(*f2)(x) - (*f2).deriv(x)*(*f1)(x)) / ((*f2)(x)*(*f2)(x));
    }

    ~Quotient() {
      delete f1;
      delete f2;
    }
  };
};


#endif
