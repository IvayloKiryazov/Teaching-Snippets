#pragma once

#include <string>
#include <stack>

/*
 * We support +, -, /, %, *
 * Note: same as Shegunov's implementation and wiki implementation.
  https://learn.fmi.uni-sofia.bg/mod/folder/view.php?id=130137
 * Difference is it supports multi digit.
 * For his infixToPostfix function just use the same while loop to
 * have it support multi digit.

   From
   else if ((expr[i] >= '0' && expr[i] <= '9')) {
      postfixNotation.push_back(expr[i]);
   }
   To:
   else if ((expr[i] >= '0' && expr[i] <= '9')) {
      while(std:isDigit(expr[i]){
      .... and so on.
      postfixNotation.push_back(expr[i]);
   }
 */

long long calculateRPN(const std::string& input) {
   std::stack<long long> calculations;
   for (long long i = 0; i < input.size(); ++i) {
      if (input[i] == ' ') {
         continue;
      }
      if (std::isdigit(input[i])) {
         //Might be a smarter way for multi-digit :)
         std::string numb(&input[i]);
         while (std::isdigit(input[++i])) {
            numb.append(&input[i]);
         }
         if (input[i] != ' ') {
            return -1;
         }
         long long result = std::stoi(numb);
         calculations.push(result);
      }
      else {
         // Start with second, because it's Reverse :)
         long long second = calculations.top();
         calculations.pop();
         long long first = calculations.top();
         calculations.pop();
         switch (input[i]) {
            case'+':
               calculations.push(first + second);
               break;
            case'-':
               calculations.push(first - second);
               break;
            case'/':
               calculations.push(first / second);
               break;
            case'%':
               calculations.push(first % second);
               break;
            case'*':
               calculations.push(first * second);
               break;
            default:
               return -1;
         }
      }
   }
   return calculations.top();
}
