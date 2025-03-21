#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <vector>

// Using wide characters (wchar_t) to handle Unicode
using CharType = wchar_t;
using namespace std::string_literals;

// Define the pairs using an initializer list
const std::unordered_map<CharType, CharType> pairs = {
    {'(', ')'},  // Basic Latin parentheses
    {'[', ']'},
    {'{', '}'},
    {'<', '>'},  // Angle brackets
    {'«', '»'},  // Guillemets (French quotes)
    {'‹', '›'}, // Single Guillemets

    // CJK parentheses (fullwidth forms)
    {'（', '）'}, // Fullwidth parenthesis
    {'【', '】'}, // Fullwidth square brackets
    {'｛', '｝'}, // Fullwidth curly brackets
    {'〈', '〉'}, // Fullwidth angle brackets
    {'《', '》'}, // Double angle brackets
    {'「', '」'}, // Corner brackets
    {'『', '』'}, // White corner brackets
    {'〔', '〕'},
    {'〖', '〗'},
    {'〘', '〙'},
    {'〚', '〛'},
};

// Predefined set of values (closing parentheses)
const std::unordered_set<CharType> values = []() {
    std::unordered_set<CharType> vals;
    for (const auto& pair : pairs) {
        vals.insert(pair.second);
    }
    return vals;
}(); // Immediately invoked lambda to initialize the set



std::string parenthesesBalancer(const std::wstring& str) {
    std::stack<CharType> stack;
    std::wstringstream ss;

    for (CharType c : str) {
        if (pairs.contains(c)) {
            // If c is an opening parenthesis
            stack.push(c);
            ss << c;
        } else if (values.contains(c)) {
            // If c is a closing parenthesis
            if (!stack.empty() && pairs.at(stack.top()) == c) {
                // Parentheses matches
                ss << c;
                stack.pop();
            } else {
                // Parentheses does not match
                ss << c;
            }
        } else {
            // If c isn't a parenthesis
            ss << c;
        }
    }

    while (!stack.empty()) {
        CharType opening = stack.top();
        ss << pairs.at(opening);
        stack.pop();
    }

    std::wstring result = ss.str();
    return std::string(result.begin(), result.end());
}

int main() {
    // Test cases
    std::vector<std::wstring> testCases = {
        L"Hello (world)",
        L"aaa(b]b(c(ddd)d]",
        L"This is a [test] with {nested (parentheses)}",
        L"Unbalanced ((example]",
        L"CJK examples: 「こんにちは」「世界」",
        L"Mixed types: (「Hello」)",
        L"Invalid closing parenthesis: test)"
    };

    std::cout << "Testing parentheses balancer:\n";
    for (const auto& test : testCases) {
        std::wcout << L"Input: " << test << std::endl;
        std::cout << "Result: " << parenthesesBalancer(test) << std::endl;
        std::cout << "------------------------\n";
    }

    return 0;
}