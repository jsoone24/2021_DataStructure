#include "includes/EvalMathEq.h"
#include <iostream>
#include <string>

int main(){
    /*
    // calsPostfix 테스트
    std::cout << "수식 입력 (Postfix)= " << "\n";
    double res = calcPostfixExpr();    
    std::cout << "계산 결과 => "<< res << "\n";
    const char* input = "30 20 100 + *";
    std::cout << "미리 입력된 수식 (Postfix)= " << input << "\n";
    res = calcPostfixExpr(input);
    std::cout << "계산 결과 => "<< res << "\n";

    // infix2Postfix 테스트
    std::cout << "수식 입력 (Infix)= " << "\n";
    std::string res2 = infix2Postfix();
    std::cout << "변환 결과 => " << res2 << "\n";
    const char* input2 = ("30 + 20 * 100");
    std::cout << "미리 입력된 수식 (Infix)= " << input2 << "\n";    
    res2 = infix2Postfix(input2);
    std::cout << "변환 결과 => " << res2 << "\n";
    */ 
   
    // 결합 테스트
    std::cout << "수식 입력 (Infix)= " << "\n";
    std::string res3 = infix2Postfix();
    std::cout << "변환 결과 => " << res3 << "\n";
    std::cout << "미리 입력된 수식 (Postfix)= " << res3 << "\n";
    std::cout << "계산 결과 => "<< calcPostfixExpr(res3) << "\n";
    return 0;
}