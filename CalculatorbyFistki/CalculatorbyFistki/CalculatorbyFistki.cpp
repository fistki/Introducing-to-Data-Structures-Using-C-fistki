#include "calc_fistki.h"
#include <iostream>
#include <string>
#include <cstdio>

int main(void)
{
	// 중위 표기법을 후위 표기법으로 바꾸기
	std::string exp1 = "1+2*3";
	std::string exp2 = "(1+2)*3";
	std::string exp3 = "((1-2)+3)*(5-2)";

	calc_fistki::ConvToRPNExp(exp1);
	calc_fistki::ConvToRPNExp(exp2);
	calc_fistki::ConvToRPNExp(exp3);

	std::cout << exp1 << std::endl;
	std::cout << exp2 << std::endl;
	std::cout << exp3 << std::endl;

	printf("\n\n");

	// 중위 표기법으로 표현된 수식 계산하기
	exp1 = "1+2*3";
	exp2 = "(1+2)*3";
	exp3 = "((1-2)+3)*(5-2)";
	
	std::cout << exp1 << " = " << calc_fistki::EvalRPNExp(exp1) << std::endl;
	std::cout << exp2 << " = " << calc_fistki::EvalRPNExp(exp2) << std::endl;
	std::cout << exp3 << " = " << calc_fistki::EvalRPNExp(exp3) << std::endl;
	
	return 0;
}