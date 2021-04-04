/**
 * File: precedence.c
 * Description: Variety of functions to calculate order of precedence
 */


// Calculate the order of precedence
int getPrecedence(char op) {
    switch (op){
        // Implement BEDMAS
        case '+':
        case '-':
            return 1;
  
        case '*':
        case '/':
            return 2;
  
        case '^':
            return 3;
    }
    return -1;
}

