#ifndef __add_h__
#define __add_h__

#include <vector>

#include "function.hh"

namespace AutoDiff {

  class Add : public Function {

  private:
    const Function* const f1;
    const Function* const f2;

  public:
    Add(const Function& f1_in, const Function& f2_in) : f1{&f1_in}, f2{&f2_in} {} 
    
    double operator()(const double& x) const {
      return (*f1)(x) + (*f2)(x);
    }

    double deriv(const double& x) const {
      return (*f1).deriv(x) + (*f2).deriv(x);
    }

    ~Add() {
      delete f1;
      delete f2;
    }
  };
};


#endif
