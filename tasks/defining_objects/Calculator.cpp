/*
 * Calculator.cpp
 *
 *  Created on: June 18, 2015
 *      Author: Matthew Mussomele
 */

#include <cstdint>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "Calculator.h"
 
///////////////////////////////////////////////////////////////////////
// This assignment is going to be much more independent than your    //
// past tasks. You are expected to fully implement the Calculator    //
// class from scratch. Your implementation must have the following   //
// public functions, along with a constructor and destructor:        //
//                                                                   //
//     double add(double x, double y)                                // 
//     double mul(double x, double y)                                //
//     double sub(double x, double y)                                //
//     double div(double x, double y)                                //
//     double add_stored(double x)                                   // 
//     double mul_stored(double x)                                   //
//     double sub_stored(double x)                                   //
//     double div_stored(double x)                                   //
//     void store(double value);                                     //
//     std::string get_call(int32_t item)                            //
//                                                                   //
// Note: You may have as many private variables and functions as you //
//       want.                                                       //
//                                                                   //
// The get_call function is a bonus and you are not expected to know //
// how to do it quickly. It should be more challenging than the rest //
// of this task, which is simply meant to have you practice object   // 
// syntax.                                                           //
//                                                                   //
// You have been given complete makefiles and test files for this    //
// task to allow you to focus on defining calculator.                //
//                                                                   //
// Use the Dog class from the presentation as a reference if you     //
// don't remember all the syntax.                                    //
//                                                                   //
// Question 1: Define the add, mul, sub and div methods.             //
//             Add should return the sum of two doubles              //
//             Mul should return the product of two doubles          //
//             Sub should return the difference of two doubles       //
//             Div should return the first double divided by the     //
//                 second, or 0 if the second number is zero.        //
//                                                                   //
// Question 2: Store should take in a value and store it in the      //
//             calculator for later use. This value should default   //
//             to zero. After you've implemented store, write        //
//             additional versions of the calculator functions that  //
//             take only one argument and who's names end in         //
//             '_stored'. These will assume that the stored value is //
//             the second argument of the original functions.        //
//                                                                   //
// Question 3: Write the get_call function. It should take in an     //
//             integer and return the nth last call made to the      //
//             calculator.                                           //
//             The format should be like the following:              //
//             x + y = z                                             //
//             Where x is the first argument, y is the second and    //
//             z is the answer. The "+" should be replaced with the  //
//             relevant operator.                                    //
//             All doubles should be accurate to 3 sig figs.         //
//             When logging division calls, if the user tried to     //
//             divide by zero, get_call should return                //
//             "Error: Divide by Zero"                               // 
//             When a value is stored, get_call should return        //
//             "Stored: x" where x is replaced by the value stored.  //
//             If an invalid history index is attempted to be seen,  //
//             simply return "No record"                             //
//                                                                   //
// HINT: For question three, you may find the following useful:      //
//       std::ostringstream allows you to 'print' to a variable      //
//       just like you would to cout.                                //
//       To get the string resulting from 'printing' to the variable //
//       use the std::ostringstream.str() method.                    //
//       You can use the std::setprecision function to set the       //
//       number of decimal places to print.                          //
//       Example:                                                    //
//          std::ostringstream example;                              //
//          example << std::setprecision(3) << 5.23523;              //
//          return example.str();                                    //
//                                                                   //
//          The above would return '5.23'.                           //
///////////////////////////////////////////////////////////////////////
