reverse-polish-calculator
=========================
In reverse Polish notation the operators follow their operands. To add 3 and 4, one would write "3 4+" rather than "3 + 4".
If there are multiple operations, the operator is given immediately after its second operand
The expression written "3 - 4 + 5” would be written "3 4- 5 +" in RPN: first subtract 4 from 3, then add 5 to that
An advantage of RPN is that it obviates the need for parentheses that are required by infix notation.

* Produce a Reverse Polish Notation calculator that operates on input files.
* First, ask the user for the location of an input text file. Open this file.
* Read in the input text file, and interpret the input data as RPN. Each line in the file should be interpreted as its own math problem.
* Display the resulting answers to the screen, with each output line corresponding to the input lines.
* If a math problem has an error in its syntax, display SYNTAX ERROR for that line and continue with the next problem.
* Do not support unary operators. The user will not be able to enter negative numbers.
* Add support for the following binary operators, written exactly as shown: + - * / % pow
* Support decimal number inputs as well as integer number inputs.

The pow operator should raise the first operand to the power of the second operand. The % operator should perform modulo division. The C standard library supports modulo division of floating point numbers, whereas the built-in C++ modulo division operator only supports integer division. You will need to use the library function in order to handle the potential decimal number inputs from the user.

There will be one or more whitespace characters between two numbers. There will be zero or more whitespace characters between a number and a symbol or two symbols.

Sample Input:
3 4 5.0 * -

7

4. * 8 30 + 5. 

banana

9 10 + 30 -

4. 7 3-+ 2 -3+

900 40.65-20+

45.2        23.999%

Sample Output:
-17   
7    
SYNTAX ERROR   
SYNTAX ERROR    
-11  
9  
879.35  
21.201   

 	
