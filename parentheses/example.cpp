#include <iostream>
#include <stack>
#include <string>

bool parentheses_validator(const std::string& str) {
  std::stack<char> s;

  for (char c : str) {
    if (c == '(' || c == '[' || c == '{') {
      s.push(c);
    } else if (c == ')' || c == ']' || c == '}') {
      if (s.empty()) {
        return false; // Closing bracket without matching opening bracket
      }

      char top = s.top();
      s.pop();

      if ((c == ')' && top != '(') ||
          (c == ']' && top != '[') ||
          (c == '}' && top != '{')) {
        return false; // Mismatched brackets
      }
    }
  }

  return s.empty(); // True if all opening brackets have been matched
}


int main() {
  std::string test1 = "(){}[]";
  std::string test2 = "([{}])";
  std::string test3 = "((])";
  std::string test4 = "(";
  std::string test5 = ")";
  std::string test6 = "{{[()]}}";
  std::string test7 = "{[}"; // Unmatched
  std::string test8 = "((()))";
  std::string test9 = "";  // Empty String
  std::string test10 = "{[()]}(){[()]}";



  std::cout << test1 << ": " << (parentheses_validator(test1) ? "Valid" : "Invalid") << std::endl; // Valid
  std::cout << test2 << ": " << (parentheses_validator(test2) ? "Valid" : "Invalid") << std::endl; // Valid
  std::cout << test3 << ": " << (parentheses_validator(test3) ? "Valid" : "Invalid") << std::endl; // Invalid
  std::cout << test4 << ": " << (parentheses_validator(test4) ? "Valid" : "Invalid") << std::endl; // Invalid
  std::cout << test5 << ": " << (parentheses_validator(test5) ? "Valid" : "Invalid") << std::endl; // Invalid
  std::cout << test6 << ": " << (parentheses_validator(test6) ? "Valid" : "Invalid") << std::endl; // Valid
  std::cout << test7 << ": " << (parentheses_validator(test7) ? "Valid" : "Invalid") << std::endl; // Invalid
  std::cout << test8 << ": " << (parentheses_validator(test8) ? "Valid" : "Invalid") << std::endl; // Valid
  std::cout << test9 << ": " << (parentheses_validator(test9) ? "Valid" : "Invalid") << std::endl; // Valid (empty string is considered valid)
  std::cout << test10 << ": " << (parentheses_validator(test10) ? "Valid" : "Invalid") << std::endl; //Valid

    return 0;
}