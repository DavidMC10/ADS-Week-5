//================================================================================
// Name        : practical5.cpp
// Author      : McElhinney-D1@ulster.ac.uk
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

	for (size_t i = 0; i < infix.length(); i++) {
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

// Function to check whether two characters are opening 
// and closing of same type. 
bool ArePair(char opening, char closing)
{
	if (opening == '(' && closing == ')') return true;
	else if (opening == '{' && closing == '}') return true;
	else if (opening == '[' && closing == ']') return true;
	return false;
}

// Post-Condition: return true if expr contains matching brackets otherwise false
bool bracketCheck(string expr) {

	Stack<char> cs(expr.length()); // Creates a stack the length of the string

	for (int i{ 0 }; i < expr.length(); i++) {

		// If opening bracket push to stack
		if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
			cs.push(expr[i]);
			
		} else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {

			// If closing bracket does not exit or stack is empty, return false.
			if (cs.isEmpty() == true || !ArePair(cs.top(),expr[i])) {
				return false;
			} else {
				cs.pop(); // Otherwise remove element from the top of the stack
			}
		}
	}

	return cs.isEmpty() ? true : false;
}



// Pre-Condition: infix is a valid expression containing single digit numbers
// Post-Condition: returns the result of the expression evaluation
int evaluateInfixExpression(string infix) {

	std::string postfix{ infix2postfix(infix) }; // Convert infix to postfix
	Stack<int> is; // Create stack
	
	for (int i{ 0 }; i < postfix.length(); i++) {

		if (isdigit(postfix[i])) {
			// We saw an operand, push the digit onto the stack
			is.push(postfix[i] - '0');
		} else {

			// We have an operator
			// Pop the two operands from the stack and evaluate using the current operator
			int op1 = is.top();
			is.pop();
			int op2 = is.top();
			is.pop();

			int val;
			// Checks for which operator and then carries out arithmetic
			switch (postfix[i]) {
			case '+': val = op2 + op1;
				std::cout << op2 << " + " << op1 << " = " << val << endl;
				break;
			case '-': val = op2 - op1;
				std::cout << op2 << " - " << op1 << " = " << val << endl;
				break;
			case '*': val = op2 * op1;
				std::cout << op2 << " * " << op1 << " = " << val << endl;
				break;
			case '/': val = op2 / op1;
				std::cout << op2 << " / " << op1 << " = " << val << endl;
				break;
			}
			is.push(val); // Push result to the stack
		}
	}

	std::cout << "Answer = " << is.top() << endl;
	return is.top();
}


// Post-Condition: returns true if string is a palindrome, otherwise false
bool isPalindrome(string str) {

	// Declare Stack and Queue the length of the string
	Stack<char> cs(str.length());
	Queue<char> q(str.length());

	for (int i{ 0 }; i < str.length(); i++) {

		// if string character is alphabetical add to queue and stack
		if (isalpha(str[i])) {
			q.enqueue(tolower(str[i])); // Place element at the end of queue
			cs.push(tolower(str[i])); // Place element on top of the stack
		}
	}

	// Loop while the queue is not empty
	while (!q.isEmpty()) {

		// If queue and stack elements aren't equal return false
		if (q.peek() != cs.top())
			return false;

		q.dequeue(); // Remove element from the start of the queue.
		cs.pop(); // Remove element from the top of the stack
	}

	return true;
}


//------  Following are driver functions called from main function to test the functions completed above ----------

// Provides an expression evaluator sentinel loop
void testSingleDigitCalculator() {

	// complete this function using a sentinel controlled loop to
	// continually request user to enter an expression to evaluate, then print the result
	// loop can be terminated by entering 'quit'
	std::string str;
	do {
		cout << "Enter an expression (quit to terminate): ";
		cin >> str;

		if (str == "quit")
			break;

	} while (str != "quit");

}


// Provides a palindrome evaluator sentinel loop
void testPalindromeChecker() {

	// complete this function using a sentinel controlled loop to
	// continually request user to enter an string to check for palindrome, then print the result
	// loop can be terminated by entering 'quit'

	std::string str;
	do {
		cin >> str;
		cout << "Is Palindrome: " << str << " " << isPalindrome(str) << std::endl; // print the string input
	} while (str != "quit");

}

// Main method.
int main() {

	/*std::string test{ "a{b(c[d]e)f}" };
	std::cout << bracketCheck(test) << std::endl;*/

	// testPalindromeChecker();

	 testSingleDigitCalculator();

	// ---------------------------------------------------
	cout << endl << "Press enter to quit";
	cin.get();
	return 0;
}
