/************************************************************
 * Name  : function_factory.cc
 * Author: Kevin Mooney
 * Date  : 06/03/16
 * 
 * Definitions from the function_factory class
 * 
 * new_argument() is called recursively until a 0 is returned
 *
 * TODO:
 * Need to implement error checking with cin
 * reading in non-numbers + out of range + multiple numbers
 *
 * Could implement loops around the switch statements 
 ************************************************************/

#include <iostream>
#include <vector>

#include "function_factory.hh"
#include "polynomial.hh"
#include "trig.hh"
#include "hyper.hh"
#include "exp.hh"
#include "log.hh"
#include "add.hh"
#include "product.hh"
#include "quotient.hh"
#include "power.hh"

#include "test1.hh"
#include "test2.hh"
#include "test3.hh"
#include "test4.hh"

using namespace AutoDiff;

Function* new_argument();

// If more than one input is given in a line it will be ignored
// better implementation would be if we passed a range of in values too
int read_in_option() {
  int option;
  std::cin  >> option;
  std::cin.ignore(10000, '\n');	// ignore trailing characters

  if ( std::cin.good() )
    return option;
  else
    return -1;
}

// Reads in an option for a function
// Could possibly use enums
int get_option() {
  int option;
  
  std::cout << "The options are:\n";
  std::cout << "0 - As is       \t";
  std::cout << "1 - polynomial  \t";
  std::cout << "2 - trigonometric\n";
  std::cout << "3 - hyperbolic  \t";
  std::cout << "4 - exponential \t";
  std::cout << "5 - logarithmic \n";
  std::cout << "The composers are:\n";
  std::cout << "6 - addition    \t";
  std::cout << "7 - product     \n";
  std::cout << "8 - quotient    \t";
  std::cout << "9 - power       \n";
  std::cout << "\n";

  std::cout << "Pick an option: ";
  option = read_in_option();
  std::cout << std::endl; 
    
  return option;
}

// reads in trig options
int get_trig_option() {
  int option;

  std::cout << "The options are:\n";
  std::cout << "0 - sin         \t";
  std::cout << "1 - cos         \n";
  std::cout << "2 - tan         \t";
  std::cout << "3 - cot         \n";

  std::cout << "\nPick an option: "; 
  option = read_in_option();
  std::cout << std::endl;

  return option;
}

// reads in hyperbolic options
int get_hyper_option() {
  int option;

  std::cout << "The options are:\n";
  std::cout << "0 - sinh        \t";
  std::cout << "1 - cosh        \n";
  std::cout << "2 - tanh        \t";
  std::cout << "3 - coth        \n";

  std::cout << "\nPick an option: "; 
  option = read_in_option();
  std::cout << std::endl;

  return option;
}

// Creates a polynomial
Function* poly_create() {
  int order;
  Function* f_in;

  // Check what order polynomial is required then initialise a vector
  // to hold the coefficients
  std::cout << "Polynomials are of type, a + b*f(x) + c*f(x)*f(x) + ...\n";
  std::cout << "What order polynomial would you like? ";
  order = read_in_option();

  // Read in the coefficients
  std::vector<double> coefficients(order+1);
  std::cout << "Please enter the coefficients a b c ... separated by spaces\n";
  for ( int i=0; i<=order; i++ ) {
    std::cin >> coefficients[i];
  }
  std::cin.ignore(10000, '\n');
  
  std::cout << "Pick f(x):";
  f_in = new_argument();

  return new Polynomial(coefficients,*f_in);
}

// Create a trignometric function
Function* trig_create() {
  int trig_option;
  Function* f_in;

  std::cout << "Trig functions:\n";
  trig_option = get_trig_option();

  std::cout << "Choose an argument:\n";
  f_in = new_argument();

  if ( f_in != nullptr ) {  
    switch(trig_option) {
    case 0:
      return new Sin(*f_in);
    case 1:
      return new Cos(*f_in);
    case 2:
      return new Tan(*f_in);
    case 3:
      return new Cot(*f_in);
    default:
      std::cerr << "Unrecognised option" << std::endl; 
    }
  }
  return nullptr;
}

// Create a hyperbolic function
Function* hyper_create() {
  int hyper_option;
  Function* f_in;

  std::cout << "Hyperbolic functions:\n";
  hyper_option = get_hyper_option();

  std::cout << "Choose an argument:\n";
  f_in = new_argument();

  if ( f_in != nullptr ) {  
    switch(hyper_option) {
    case 0:
      return new Sinh(*f_in);
    case 1:
      return new Cosh(*f_in);
    case 2:
      return new Tanh(*f_in);
    case 3:
      return new Coth(*f_in);
    default:
      std::cerr << "Unrecognised option" << std::endl; 
    }
  }

  return nullptr;
}

// creates an exponential function
Function* exp_create() {
  std::cout << "Exponentials are of the form exp(f(x))\n";
  std::cout << "Pick f(x)";
  Function * f_in = new_argument();
  return new Exp(*f_in);
}

// creates a logarithmic function
Function* log_create() {
  std::cout << "Logarithms are of the form log(f(x))\n";
  std::cout << "Pick f(x)";
  Function * f_in = new_argument();
  return new Log(*f_in);
}

// creates a an add composition
Function* add_create() {
  std::cout << "Additions are of the form fa(x) + fb(x)\n";
  std::cout << "Pick fa(x)";
  Function * f1_in = new_argument();
  std::cout << "Pick fb(x)";
  Function * f2_in = new_argument();
  return new Add(*f1_in,*f2_in);
}

// creates a product composition
Function* prod_create() {
  std::cout << "Products are of the form fa(x) * fb(x)\n";
  std::cout << "Pick fa(x)";
  Function * f1_in = new_argument();
  std::cout << "Pick fb(x)";
  Function * f2_in = new_argument();
  return new Product(*f1_in,*f2_in);
}

// creates a quotient composition
Function* quot_create() {
  std::cout << "Products are of the form fa(x) / fb(x)\n";
  std::cout << "Pick fa(x)";
  Function * f1_in = new_argument();
  std::cout << "Pick fb(x)";
  Function * f2_in = new_argument();
  return new Quotient(*f1_in,*f2_in);
}

// creates a power composition and asks for exponent
Function* pow_create() {
  double exponent;

  std::cout << "Powers are of the form x^exponent\n";
  std::cout << "Enter the exponent: ";
  std::cin  >> exponent;

  Function * f_in = new_argument();
  return new Power(exponent,*f_in);
}

// initiates the function creater
// this will be called recursively until a 0 is returned
// add, prod and quot will all call new_argument() twice
Function* new_argument() {
  int option;
  
  option = get_option();

  switch(option) {
  case 0:			
    return new Function;	// this needs to be cleaned up
  case 1:
    return poly_create();
  case 2:
    return trig_create();
  case 3:
    return hyper_create();
  case 4:
    return exp_create();
  case 5:
    return log_create();
  case 6:
    return add_create();
  case 7:
    return prod_create();
  case 8:
    return quot_create();
  case 9:
    return pow_create();
  default:
    std::cerr << "Unrecognised option" << std::endl; 
  }
  
  return nullptr;
}

// returns user inputed function
Function* TheFunctionFactory::create() {

  std::cout << "Welcome to the function factory\n";
  std::cout << "===============================\n";
  std::cout << "To start our function is f_0(x) = f_1(x)\n";
  std::cout << "Pick f_1(x)\n\n";
  return new_argument();
}

// Returns a test function
Function* TheFunctionFactory::test(double x) {
  int funcNum;

  std::cout << "What test function would you like?\n";
  std::cout << "The options are:\n";
  std::cout << "0 - sin(x)                            \t";
  std::cout << "1 - tan(x*x + 2*x + 1)                \n";
  std::cout << "2 - exp(x^2.5) / ( log(x) + coth(x) ) \t";
  std::cout << "3 - 5*tan(x^(2.5))/(x^3 + 25*x + 9) ) \n";
  std::cout << "\nTest function number: ";
  funcNum = read_in_option();  
  std::cout << std::endl;

  switch(funcNum) { 
  case 0:
    return new Test1;
    break;
  case 1:
    return new Test2;
    break;
  case 2:
    return new Test3;
  case 3:
    return new Test4;
  default:
    std::cerr << "test function not recognised" << std::endl;
    break;
  }
  return nullptr;
}
