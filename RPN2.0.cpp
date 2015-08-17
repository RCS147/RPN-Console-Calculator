//RPN Calculator II
#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <cmath>
using namespace std;

void getMono(stack<double> & operation, string & input, int & inputLength, double & x)
{
	if(inputLength > 0)
	{
		operation.push(atof(input.c_str()));
		input = "";
		inputLength = 0;
	}
	if(!operation.empty())
	{
		x = operation.top();
		operation.pop();
	}
	else
	{
		x = 0;	
	}
}

void getMulti(stack<double> & operation, string & input, int & inputLength, double & x, double & y)
{
	if(inputLength > 0)
	{
		operation.push(atof(input.c_str()));
		input = "";
		inputLength = 0;
	}
	if(!operation.empty())
	{
		x = operation.top();
		operation.pop();
	}
	else
	{
		x = 0;	
	}
	if(!operation.empty())
	{
		y = operation.top();
		operation.pop();
	}
	else
	{
		y = 0;	
	}	
}

double fact(int x)
{
	if(x > 0)
	{
		for(int i = x-1; i > 1; i--)
			x *= i;
		return x;
	}
	else
	{
		cout << "ERROR";
		return -1;
	}
}

int main()
{
	char c;
	string input;
	stack<double> operation;
	int inputLength = 0;
	bool rad = false, newline = false, run = true;
	double x, y;
	
	while(run)
	{
		c = getch();
		
		switch(c)
		{
			//Numeric characters
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '.':
			case 'e':
				if(newline)
					cout << endl;
				cout << c;
				input = input + c;
				inputLength ++;
				newline = false;
			break;
			
			//Use the underscore character as a negative sign, to differentiate from the - operator
			case '_':
				if(newline)
					cout << endl;
				cout << '-';
				input = input + '-';
				inputLength ++;
			break;
			
			case '\b':	//Backspace
				if(inputLength > 0)
				{
					cout << "\b \b"; //Back up the cursor, overwrite with space then resume
					inputLength --;
					input.erase(input.begin() + inputLength, input.end());
				}
			break;
			
			case (char)13:	//Enter
				if(inputLength > 0)
				{
					operation.push(atof(input.c_str()));
					input = "";
					inputLength = 0;
					newline = true;
				}
			break;
			
			case '~':	//Quit
				run = false;
			break;
			
			case ' ':
				system("CLS");
				while(!operation.empty())
					operation.pop();
				newline = false;
			break;
			
			case '?':
				system("RPNhelp.txt");
			break;
			
			//**************************** Mono ****************************
			case 'Q':	//Square
				getMono(operation, input, inputLength, x);
				operation.push(x*x);
				cout << "^2" << endl << operation.top();
				newline = true;
			break;
			
			case 'q':	//Square Root
				getMono(operation, input, inputLength, x);
				operation.push(pow(x, 1/2.0));
				cout << "sqrt" << endl << operation.top();
				newline = true;
			break;
				
			case 'L':	//ln
				getMono(operation, input, inputLength, x);
				operation.push(log(x));
				cout << "ln" << endl << operation.top();
				newline = true;
			break;
			
			case 'E':	//e^x
				getMono(operation, input, inputLength, x);
				operation.push(exp(x));
				cout << "e^" << endl << operation.top();
				newline = true;
			break;
			
			case 's':	//sin(x)
				getMono(operation, input, inputLength, x);
				operation.push(sin(x));
				cout << "sin" << endl << operation.top();
				newline = true;
			break;
			
			case 'S':	//arcsin(x)
				getMono(operation, input, inputLength, x);
				operation.push(asin(x));
				cout << "sin-1" << endl << operation.top();
				newline = true;
			break;
			
			case 'c':	//cos(x)
				getMono(operation, input, inputLength, x);
				operation.push(cos(x));
				cout << "cos" << endl << operation.top();
				newline = true;
			break;
			
			case 'C':	//arccos(x)
				getMono(operation, input, inputLength, x);
				operation.push(acos(x));
				cout << "cos-1" << endl << operation.top();
				newline = true;
			break;
			
			case 't':	//tan(x)
				getMono(operation, input, inputLength, x);
				operation.push(tan(x));
				cout << "tan" << endl << operation.top();
				newline = true;
			break;
			
			case 'T':	//arctan(x)
				getMono(operation, input, inputLength, x);
				operation.push(atan(x));
				cout << "tan-1" << endl << operation.top();
				newline = true;
			break;
			
			case 'd':	//rad to deg
				getMono(operation, input, inputLength, x);
				operation.push(180*x/M_PI);
				cout << "->DEG" << endl << operation.top();
				newline = true;
			break;
			
			case 'r':	//deg to rad
				getMono(operation, input, inputLength, x);
				operation.push(M_PI*x/180);
				cout << "->RAD" << endl << operation.top();
				newline = true;
			break;
			
			case '\\':	//1/x
				getMono(operation, input, inputLength, x);
				operation.push(1/x);
				cout << "^-1" << endl << operation.top();
				newline = true;
			break;
			
			case 'x':	//10^x
				getMono(operation, input, inputLength, x);
				operation.push(pow(10,x));
				cout << " 10^" << endl << operation.top();
				newline = true;
			break;
			
			case '!':
				getMono(operation, input, inputLength, x);
				operation.push(fact(x));
				cout << "!" << endl << operation.top();
				newline = true;
			break;
			
			//**************************** Multi ****************************
			case '+':	//Addition
				getMulti(operation, input, inputLength, x, y);
				operation.push(y+x);
				cout << "+" << endl << operation.top();
				newline = true;
			break;
			
			case '-':	//subtraction
				getMulti(operation, input, inputLength, x, y);
				operation.push(y-x);
				cout << "-" << endl << operation.top();
				newline = true;
			break;
				
			case '*':	//multiplication
				getMulti(operation, input, inputLength, x, y);
				operation.push(y*x);
				cout << "*" << endl << operation.top();
				newline = true;
			break;
			
			case '/':	//division
				getMulti(operation, input, inputLength, x, y);
				operation.push(y/x);
				cout << "/" << endl << operation.top();
				newline = true;
			break;
			
			case '%':	//X% of Y
				getMulti(operation, input, inputLength, x, y);
				operation.push(0.01*x*y);
				cout << "%" << endl << operation.top();
				newline = true;
			break;
			
			case 'l': //log_y(x) using change of base formula
				getMulti(operation, input, inputLength, x, y);
				operation.push(log(x)/log(y));
				cout << "log" << endl << operation.top();
				newline = true;
			break;
			
			case '^':	//y^x
				getMulti(operation, input, inputLength, x, y);
				operation.push(pow(y, x));
				cout << "^" << endl << operation.top();
				newline = true;
			break;
			
			case 'p': //Permutations
				getMulti(operation, input, inputLength, x, y);
				operation.push(fact(x)/fact(x-y));
				cout << "P" << endl << operation.top();
				newline = true;
			break;
			
			case 'P': //Combinations
				getMulti(operation, input, inputLength, x, y);
				operation.push(fact(x)/(fact(y)*fact(x-y)));
				cout << "^" << endl << operation.top();
				newline = true;
			break;
		}
	}
	
	return EXIT_SUCCESS;
}
