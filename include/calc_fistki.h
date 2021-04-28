#pragma once
#include "InfixToPostfix.h"
#include "linkedliststack.h"
#include <string>

namespace calc_fistki {

	int EvalRPNExp(const std::string& exp)
	{
		LStack<int> stack;
		std::string convExp(exp);

		char tok = 0;
		int op1 = 0, op2 = 0;

		ConvToRPNExp(convExp);

		for (size_t i = 0; i < convExp.size(); ++i)
		{
			tok = convExp[i];
			if (std::isdigit(tok))
			{
				stack.push(tok - '0');
			}
			else
			{
				if (stack.empty()) return 0x8FFFFFFF;
				op2 = stack.pop();
				op1 = stack.pop();

				switch (tok)
				{
				case calc_fistki::PLUS:
					stack.push(op1 + op2);
					break;
				case calc_fistki::MINUS:
					stack.push(op1 - op2);
					break;
				case calc_fistki::MUL:
					stack.push(op1 * op2);
					break;
				case calc_fistki::DIV:
					stack.push(op1 / op2);
					break;
				}
			}
		}
		return stack.pop();
	}
}
