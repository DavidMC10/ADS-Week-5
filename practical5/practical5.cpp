//================================================================================
// Name        : practical5.cpp
// Author      : a.mccaughey@ulster.ac.uk
// Version     : 1.0
// Description : practical 5 test program to utilise Static Stack/Queue classes
//================================================================================

#include <string>	// string type
#include <cstddef>	// size_t (an unsigned integer type used for sizes)
#include <cctype>	// tolower, toupper, isalpha, isdigit etc

#include "ArrayStack.h"
#include "ArrayQueue.h"

using namespace std;

// Pre-Condition: c contains '-', '+', '/' or '*' 
// Post-Condition: '+' and '-' have lower precedence (so return 1)
//                  than '*' and '/' (so return 2)
int prec(char c) {
	if (c == '-' || c == '+') return 1; else return 2;
}

// Pre-Condition: infix is a valid infix expression containing single digit numbers
// Post-Condition returns an postfix value of expression
string infix2postfix(string infix) {
	Stack<int> s;                   // stack
	string post;                    // postfix expression

	for (size_t i = 0; i<infix.length(); i++) {
		if (isdigit(infix[i])) {      // operand
			post += infix[i];
		}
		else if (infix[i] == '(') { // opening bracket
			s.push(infix[i]);
		}
		else if (infix[i] == ')') { // closing bracket
			// add all stack elements up to open bracket to post
			while (s.top() != '(') {
				post += s.top();
				s.pop();
			}
			s.pop();  // remove opening bracket    
		}
		else {
			// must be an operator
			while (!s.isEmpty() && s.top() != '(' && prec(infix[i]) <= prec(s.top())) {
				post += s.top();
				s.pop();
			}
			s.push(infix[i]);
		}
	}
	// add remaining elements on stack to post
	while (!s.isEmpty()) {
		post += s.top();
		s.pop();
	}
	return post;
}

// Post-Condition: return true if expr contains matching brackets otherwise false
bool bracketCheck(string expr) {
	// complete this function 
	return true;
}

// Pre-Condition: infix is a valid expression containing single digit numbers
// Post-Condition: returns the result of the expression evaluation
int evaluateInfixExpression(string infix) {

	// complete this function using algorithm from notes

	return 0;
}


// Post-Condition: returns true if string is a palindrome, otherwise false
bool isPalindrome(string str) {
	// complete this function using algorithm from notes
	return true;
}


//------  Following are driver functions called from main function to test the functions completed above ----------

// Provides an expression evaluator sentinel loop
void testSingleDigitCalculator() {

	// complete this function using a sentinel controlled loop to
	// continually request user to enter an expression to evaluate, then print the result
	// loop can be terminated by entering 'quit'

}


// Provides a palindrome evaluator sentinel loop
void testPalindromChecker() {

	// complete this function using a sentinel controlled loop to
	// continually request user to enter an string to check for palindrome, then print the result
	// loop can be terminated by entering 'quit'

}

// Main method.
int main() {

	// testPalindromeChecker();

	// testSingleDigitCalculator();

	// ---------------------------------------------------
	cout << endl << "Press enter to quit";
	cin.get();
	return 0;
}
