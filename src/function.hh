/************************************************************
 * Name  : function.hh
 * Author: 
 * Date  : 
 * 
 * Function class
 * Taking from class notes
 ************************************************************/

#ifndef __function_h__
#define __function_h__

namespace AutoDiff {
  
  class Function {
    
  public:
    virtual double operator()(const double& x) const {return x;}
    virtual double deriv(const double& x) const {return 1.0;}
    virtual ~Function() {}
  };
};


#endif
