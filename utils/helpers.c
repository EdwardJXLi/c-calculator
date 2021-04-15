/**
 * File: precedence.c
 * Description: Variety of functions to calculate order of precedence
 */

#include "common.h"
#include "helpers.h"

// Calculate the order of precedence
int getPrecedence(char op) {
    switch (op){
        // Implement BEDMAS
        case ')':
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
  
        case '*':
        case '/':
            return 2;
  
        case '^':
            return 3;
    }
    return 0;
}

int isAlpha(char analyze)
{
    if (analyze >= 'a' && analyze <= 'z'){return true;}
    else {return false;}
}

int isNum(char analyze)
{
    if (analyze >= '0' && analyze <= '9'){return true;}
    else {return false;}
}

