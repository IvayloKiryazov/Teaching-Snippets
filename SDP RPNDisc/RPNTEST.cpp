#include "pch.h"
#include "../sdp2/RPN.h"

//Follow 
//https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2019
//in order to set yourself up.

TEST(RPN, RPNWikipediaExtended){
   const std::string test("15 7 1 1 + - / 3 * 5 2 1 1 + + - %");
   EXPECT_EQ(0, calculateRPN(test));
}

TEST(RPN, RPNWikipediaExtendedInvalidNumber) {
   const std::string test("15 7 1 1 + - / 3 * 2& 1 1 + + -");
   EXPECT_EQ(-1, calculateRPN(test));
}

TEST(RPN, RPNWikipediaExtendedInvalidOperation) {
   const std::string test("15 7 1 1 + - / 3 * 2 & 1 1 + + -");
   EXPECT_EQ(-1, calculateRPN(test));
}

