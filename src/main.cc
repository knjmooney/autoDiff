/*************************************************************
 * Name:   main.cc
 * Author: Kevin Mooney
 * Date:   08/03/16
 *
 * Tests the function factories create routine and
 * compares evaluation time between virtual
 * functions and direct implementation
 ************************************************************/

#include <iostream>
#include <chrono>
#include <unistd.h>

#include "function_factory.hh"

using namespace std;

void print_usage(char * progname) {
  fprintf(stderr,"Usage: %s [ -ht ]\n",progname);
  fprintf(stderr,"Finds the derivative of some function specified at run time\n");
  fprintf(stderr,"          -h  Prints this help                             \n");
  fprintf(stderr,"          -n  Set the number of tests to be run            \n");
}

int main(int argc, char *argv[]) {

  double argument;
  int test_size = 0;
  int option;

  // parse command line arguments
  while((option = getopt(argc,argv,"ht:")) != -1) {
    switch(option) {
    case 't':			// number of tests
      test_size = atoi(optarg);
      break;
    case 'h':			// print help
      print_usage(argv[0]);
      return EXIT_SUCCESS;
    default :			// unrecognised
      print_usage(argv[0]);
      return EXIT_FAILURE;
    }
  }

  // START INTERFACE
  AutoDiff::Function* f = AutoDiff::TheFunctionFactory::create();

  if ( f == nullptr ) {		// In case of invalid argument
    cerr << "Oops, something went wrong\n";
    return EXIT_FAILURE;
  }
  else {
    cout << "Enter x: ";
    cin  >> argument;
    cout << "\n";
    
    cout << "f (" << argument << ") = " 
	 << (*f)(argument) << endl;
    cout << "f'(" << argument << ") = " 
	 << (*f).deriv(argument) << endl; 

    // Run tests
    if ( test_size > 0 ) {
      cout << "\n=== Test Functions ===\n\n";
      AutoDiff::Function* f_test = AutoDiff::TheFunctionFactory::test(argument);
      
      cout << "f_test (" << argument << ") = " 
	   << (*f_test)(argument) << endl;
      cout << "f_test'(" << argument << ") = " 
	   << (*f_test).deriv(argument) << endl; 
      
      // run virtual tests
      auto t0 = chrono::high_resolution_clock::now();      
      for ( int i = 0; i < test_size; i++ ) {
	(*f)(argument);
	(*f).deriv(argument);
      }
      auto t1 = chrono::high_resolution_clock::now();
      chrono::duration<float> dur1 = t1 - t0;
      
      // run direct tests
      t0 = chrono::high_resolution_clock::now();      
      for ( int i = 0; i < test_size; i++ ) {
	(*f_test)(argument);
	(*f_test).deriv(argument);
      }
      t1 = chrono::high_resolution_clock::now();     
      chrono::duration<float> dur2 = t1 - t0;

      cout << "\nVirtual function : ";
      cout << dur1.count() << "s\n";
      cout << "Test function    : ";
      cout << dur2.count() << "s\n";
      
      delete f_test;
    }     
    delete f;
  }

  return EXIT_SUCCESS;
}

