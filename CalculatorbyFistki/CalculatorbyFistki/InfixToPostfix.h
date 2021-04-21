#pragma once

#include <string>
#include "linkedliststack.h"

namespace calc_fistki {
	enum Token_value {
		END,
		PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
		PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'
	};

	int GetOpPrec(const char& op)
	{
		switch (op)
		{
		case MUL: case DIV:
			return 5;
		case PLUS: case MINUS:
			return 3;
		case LP:
			return 1;
		}
		return 0;
	}
	int WhoPrecOp(const char& op1, const char& op2)
	{
		if (GetOpPrec(op1) > GetOpPrec(op2)) return 1;
		else if (GetOpPrec(op1) < GetOpPrec(op2))  return -1;
		else return 0;
	}

	void ConvToRPNExp(std::string& exp)
	{
		LStack<char> stack;

		std::string convExp;
		char tok = 0;
		char popOp = 0;
		for (size_t i = 0; i < exp.size(); ++i)
		{
			tok = exp[i];
			if (std::isdigit(exp[i]))
			{
				convExp.push_back(tok);
			}
			else
			{
				switch (tok)
				{
				case LP:
					stack.push(tok);
					break;
				case RP:
					if (stack.empty()) return;
					while (1)
					{
						popOp = stack.pop();
						if (popOp == '(') break;
						convExp.push_back(popOp);
					}
					break;
				case PLUS: case MINUS: case MUL: case DIV:
					while (!stack.empty() && WhoPrecOp(stack.peek(), tok) >= 0)
						convExp.push_back(stack.pop());
					stack.push(tok);
					break;
				}
			}
		}
		while (!stack.empty())
			convExp.push_back(stack.pop());
		std::swap(exp, convExp);
	}
}
