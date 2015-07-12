#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
#include<cstdlib>
#include<sstream>
using namespace std;

string line = " ";
string operand;
string digit;
vector<double> digitstack;
char oper;
bool result;
bool formulate(string operand);
int calculation(char oper);
string symbol("+-*/%^p");
int k;

int main()
{
	cout << "welcome to reverse Polish notation calculator" << endl;
	cout << "enter file location where you store input data" << endl;
	cout << "ex.  'c:\\input.txt'" << endl;
	cout << "if .ccp and input file in same folder then just enter file name" << endl;
	cout << "ex.  'myinput.txt'" << endl;

	char filename[50];

	ifstream infile;
	ifstream infile1;
	cin.getline(filename, 50);
	infile.open(filename);
	infile1.open(filename);
	cout << "sample input" << endl;
	cout << endl;
	while (!infile.eof())
	{
		if (infile.is_open())
		{

			getline(infile, operand);
			cout << operand << endl;
		}
		else
		{
			cout << "file not open" << endl;
			return 0;
		}
	}

	cout << "sample output" << endl;
	cout << endl;
	while (getline(infile1, operand))
	{
		result = formulate(operand);
		if (result == true)
		{
			
			cout << digitstack.back() << endl;

		}
		
		else
		{
			if (operand == " ")
            {
				cout << "empty data" << endl;
			}
			else
			cout << "SYNTAX ERROR" << endl;

		}
		
		digit.clear();
		digitstack.clear();
		operand.clear();
	}

	infile.close();
	infile1.close();
	return 1;
}

bool formulate(string operand)
{
	int lenght;
	lenght = operand.length();
	if (lenght == 0)
		return false;

	if (lenght == 1)
	{
		if (!isdigit(operand[0]))
			return false;
		else
		{
			digitstack.push_back(atof(operand.c_str()));
			return true;
		}
	}

	for (int i = 0; i < lenght; i++)
	{
		if (!isdigit(operand[i]) && operand[i] != '+'&& operand[i] != '-'&&operand[i] != '*'&&operand[i] != '/'&&operand[i] != '%'&&operand[i] != '^'&&operand[i] != '.'&&operand[i] != ' '&&operand[i] != 'p')
		{
			return false;
		}

		if (operand[0] == '.')
		{
			return false;
		}

		if (isdigit(operand[i]))
			digit.push_back(operand[i]);

		if (operand[i] == '.')
		{
			digit.push_back(operand[i]);
			if (operand[i + 1] == ' ')
			{
				digit.push_back(0);
			}

			
		}

		if (operand[i] == ' ')
		{

			digitstack.push_back(atof(digit.c_str()));
			digit.clear();

			int p = i - 1;

			if (operand[p] == '+' || operand[p] == '-' || operand[p] == '/' || operand[p] == '*' || operand[p] == '%' || operand[p] == 'p')
			{
				digitstack.pop_back();
			}
			if (i > 2)
			{
				if (operand[i - 3] == 'p')
				{
					digitstack.pop_back();
				}
			}

			if (operand[i - 1] == ' ')
			{
				digitstack.pop_back();
			}
		}


		if (operand[i] == 'p')
		{
			if (operand[i + 1] == 'o' && operand[i + 2] == 'w')
			{
				if (digitstack.size() < 2)
				{
					return false;
				}
				calculation('^');
			
			}
			else
				return false;
		}

		if (operand[i] == '+' || operand[i] == '-' || operand[i] == '/' || operand[i] == '*' || operand[i] == '%')
		{

			if (isdigit(operand[i - 1]))
			{
				digitstack.push_back(atof(digit.c_str()));
				digit.clear();
			}
			if (digitstack.size() < 2)
			{
				return false;
			}
			calculation(operand[i]);
		}
	}

	return true;

}

int calculation(char oper)
{
	double rhs;
	double lhs;

	if (oper == '+')
	{
		rhs = digitstack.back();
		digitstack.pop_back();
		lhs = digitstack.back();
		digitstack.pop_back();
		digitstack.push_back(lhs + rhs);
	}

	if (oper == '-')
	{
		rhs = digitstack.back();
		digitstack.pop_back();

		lhs = digitstack.back();
		digitstack.pop_back();

		digitstack.push_back(lhs - rhs);

	}

	if (oper == '*')
	{
		rhs = digitstack.back();
		digitstack.pop_back();
		lhs = digitstack.back();
		digitstack.pop_back();
		digitstack.push_back(lhs*rhs);
	}

	if (oper == '/')

	{
		rhs = digitstack.back();
		if (rhs == 0)
			formulate("*");
		digitstack.pop_back();
		lhs = digitstack.back();
		digitstack.pop_back();
		digitstack.push_back(lhs / rhs);

	}

	if (oper == '^')
	{
		rhs = digitstack.back();
		digitstack.pop_back();
		lhs = digitstack.back();
		digitstack.pop_back();
		digitstack.push_back(pow(lhs, rhs));
	}

	if (oper == '%')
	{
		rhs = digitstack.back();
		digitstack.pop_back();
		lhs = digitstack.back();
		digitstack.pop_back();
		digitstack.push_back(fmodf(lhs, rhs));
	}

	return 0;
}