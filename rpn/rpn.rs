use std::io::{self, Write};

struct RPNConverter;

impl RPNConverter {
    fn new() -> Self {
        RPNConverter
    }

    fn infix_to_rpn(&self, infix: &str) -> Result<String, String> {
        let mut rpn = String::new();
        let mut operators: Vec<char> = Vec::new();

        for c in infix.chars() {
            if self.is_operand(c) {
                // If operand, add to the RPN
                rpn.push(c);
                rpn.push(' ');
            } else if c == '(' {
                // If '(', add to the stack
                operators.push(c);
            } else if c == ')' {
                // If ')', pop from the stack until '(' is found
                while let Some(top) = operators.last() {
                    if *top != '(' {
                        rpn.push(operators.pop().unwrap());
                        rpn.push(' ');
                    } else {
                        break;
                    }
                }
                if operators.pop() != Some('(') {
                    return Err("Mismatched parentheses".to_string());
                }
            } else if self.is_operator(c) {
                // If operator, handle precedence
                while let Some(&top) = operators.last() {
                    if (c != '^' && self.precedence(c) <= self.precedence(top)) ||
                       (c == '^' && self.precedence(c) < self.precedence(top))
                    {
                        rpn.push(operators.pop().unwrap());
                        rpn.push(' ');
                    } else {
                        break;
                    }
                }
                operators.push(c);
            } else if c.is_whitespace() {
                // Ignore whitespace
                continue;
            } else {
                return Err("Invalid input".to_string());
            }
        }

        // Add any remaining operators to the RPN
        while let Some(op) = operators.pop() {
            if op == '(' {
                return Err("Mismatched parentheses".to_string());
            }
            rpn.push(op);
            rpn.push(' ');
        }

        Ok(rpn)
    }

    fn is_operand(&self, c: char) -> bool {
        c.is_alphanumeric()
    }

    fn is_operator(&self, c: char) -> bool {
        matches!(c, '+' | '-' | '*' | '/' | '^')
    }

    fn precedence(&self, op: char) -> i32 {
        match op {
            '^' => 3,
            '*' | '/' => 2,
            '+' | '-' => 1,
            _ => -1, // Lowest precedence (for '(')
        }
    }
}

fn main() -> io::Result<()> {
    let converter = RPNConverter::new();
    print!("Enter an infix expression: ");
    io::stdout().flush()?;

    let mut infix_expression = String::new();
    io::stdin().read_line(&mut infix_expression)?;

    match converter.infix_to_rpn(&infix_expression.trim()) {
        Ok(rpn_expression) => println!("RPN expression: {}", rpn_expression),
        Err(e) => eprintln!("Error: {}", e),
    }

    Ok(())
}