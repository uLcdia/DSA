use std::collections::{HashMap, HashSet};

fn main() {
    // Test cases
    let test_cases = vec![
        "Hello (world)",
        "aaa(b]b(c(ddd)d]",
        "This is a [test] with {nested (parentheses)}",
        "Unbalanced ((example]",
        "CJK examples: 「こんにちは」「世界」",
        "Mixed types: (「Hello」)",
        "Invalid closing parenthesis: test)"
    ];

    println!("Testing parentheses balancer:");
    for test in test_cases {
        println!("Input: {}", test);
        println!("Result: {}", parentheses_balancer(test));
        println!("------------------------");
    }
}

fn parentheses_balancer(input: &str) -> String {
    // Define the pairs using a HashMap
    let pairs = create_pairs();
    
    // Create set of closing parentheses
    let values: HashSet<char> = pairs.values().cloned().collect();
    
    let mut stack = Vec::new();
    let mut result = String::new();

    for c in input.chars() {
        if pairs.contains_key(&c) {
            // If c is an opening parenthesis
            stack.push(c);
            result.push(c);
        } else if values.contains(&c) {
            // If c is a closing parenthesis
            if !stack.is_empty() && pairs.get(&stack[stack.len() - 1]) == Some(&c) {
                // Parentheses matches
                result.push(c);
                stack.pop();
            } else {
                // Parentheses does not match
                result.push(c);
            }
        } else {
            // If c isn't a parenthesis
            result.push(c);
        }
    }

    // Add closing parentheses for any remaining opening ones
    while !stack.is_empty() {
        let opening = stack.pop().unwrap();
        if let Some(closing) = pairs.get(&opening) {
            result.push(*closing);
        }
    }

    result
}

fn create_pairs() -> HashMap<char, char> {
    let mut pairs = HashMap::new();
    
    // Basic Latin parentheses
    pairs.insert('(', ')');
    pairs.insert('[', ']');
    pairs.insert('{', '}');
    pairs.insert('<', '>');  // Angle brackets
    
    // Guillemets (French quotes)
    pairs.insert('«', '»');
    pairs.insert('‹', '›');  // Single Guillemets
    
    // CJK parentheses (fullwidth forms)
    pairs.insert('（', '）'); // Fullwidth parenthesis
    pairs.insert('【', '】'); // Fullwidth square brackets
    pairs.insert('｛', '｝'); // Fullwidth curly brackets
    pairs.insert('〈', '〉'); // Fullwidth angle brackets
    pairs.insert('《', '》'); // Double angle brackets
    pairs.insert('「', '」'); // Corner brackets
    pairs.insert('『', '』'); // White corner brackets
    pairs.insert('〔', '〕');
    pairs.insert('〖', '〗');
    pairs.insert('〘', '〙');
    pairs.insert('〚', '〛');
    
    pairs
} 