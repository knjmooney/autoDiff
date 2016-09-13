#ifndef __log_h__
#define __log_h__

#include <cmath>

#include "function.hh"

namespace AutoDiff {

  class Log : public Function {

  private:
    const Function* const f;

  public:	
    Log(const Function& f_in) : f{&f_in} {} 
    
    Log() : f{new Function} {}
    
    double operator()(const double& x) const {
      return log((*f)(x));
    }
    
    double deriv(const double& x) const {
      return (*f).deriv(x)/(*f)(x);
    }

    ~Log() {
      delete f;
    }
  };
};


#endif
