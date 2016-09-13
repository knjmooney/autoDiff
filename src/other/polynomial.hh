#ifndef __polynomial_h__
#define __polynomial_h__

#include <vector>

#include "function.hh"

namespace AutoDiff {

  class Polynomial : public Function {

  private:
    const Function* const f;
    const std::vector<double> p;    

  public:    
    Polynomial(const std::vector<double>& p_in , const Function& f_in) : f{&f_in}, p{p_in} {} 

    Polynomial(const std::vector<double>& p_in) : f{new Function}, p{p_in} {}
    
    double operator()(const double& x) const {
      double total(0.0), xpow(1.0), fval((*f)(x));

      for( std::size_t i(0); i<p.size(); i++ ) {
	total += xpow*p[i];
	xpow  *= fval;
      }

      return total;
    }

    double deriv(const double& x) const {
      double total(0.0), xpow(1.0), prefac(1.0), fval((*f)(x)), dfval((*f).deriv(x));

      for( std::size_t i=1; i<p.size(); i++ ) {
	prefac  = (double) i;
	total  += dfval*prefac*xpow*p[i];
	xpow   *= fval;	
      }

      return total;
    }

    ~Polynomial() {
      delete f;
    }
  };
};


#endif
