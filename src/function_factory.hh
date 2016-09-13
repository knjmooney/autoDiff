/************************************************************
 * Name  : function_factory.hh
 * Author: Kevin Mooney
 * Date  : 06/03/16
 * 
 * Function Factory class
 * 
 * Defines the function factory
 * create() returns a nullptr if it cannot continue
 ************************************************************/


#ifndef __function_factory_h__
#define __function_factory_h__

#include "function.hh"

namespace AutoDiff {  

  class TheFunctionFactory {
  public:
    // start the interactive function creater
    static Function* create();
    // test functions
    static Function* test  (double x);
  };
};

#endif
