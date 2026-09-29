#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int len = strlen(s);
    
    // An odd length string can never be valid
    if (len % 2 != 0) {
        return false;
    }
    
    // Allocate memory for the stack
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char current = s[i];
        
        // Push opening brackets onto the stack
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } 
        // Handle closing brackets
        else {
            // If stack is empty, there is no matching opening bracket
            if (top == -1) {
                free(stack);
                return false;
            }
            
            char topChar = stack[top--];
            
            // Check for mismatched bracket types
            if ((current == ')' && topChar != '(') ||
                (current == '}' && topChar != '{') ||
                (current == ']' && topChar != '[')) {
                free(stack);
                return false;
            }
        }
    }
    
    // If the stack is empty, all brackets were matched correctly
    bool isValidString = (top == -1);
    free(stack);
    return isValidString;
}
