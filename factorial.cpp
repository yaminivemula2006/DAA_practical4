#include <iostream>

// Iterative method using a for loop
// Parameter is unsigned int because factorials are only for non-negative numbers
unsigned long long factorialIterative(unsigned int n) {
    unsigned long long result = 1;
    
    for (unsigned int i = 1; i <= n; ++i) {
        result *= i;
    }
    
    return result;
}

// Recursive method using function self-calls
// Parameter is unsigned int to perfectly match types and prevent sign-mismatch errors
unsigned long long factorialRecursive(unsigned int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n <= 1) {
        return 1;
    }
    // Recursive case: types match perfectly, no implicit conversion bugs
    return n * factorialRecursive(n - 1);
}

int main() {
    int inputNum;
    
    std::cout << "Enter a  integer: ";
    std::cin >> inputNum;
    
    // 1. Check for negative numbers first before converting to unsigned
    if (inputNum < 0) {
        std::cout << "Error: Factorial is not defined for negative numbers." << std::endl;
    } 
    // 2. Check for overflow limits (unsigned long long maxes out at 20!)
    else if (inputNum > 20) {
        std::cout << "Error: Result too large! Please enter a number between 0 and 20." << std::endl;
    } 
    // 3. Safe to execute
    else {
        // Safe explicit cast to unsigned int
        unsigned int num = static_cast<unsigned int>(inputNum);
        
        std::cout << "Iterative Result: " << num << "! = " << factorialIterative(num) << std::endl;
        std::cout << "Recursive Result: " << num << "! = " << factorialRecursive(num) << std::endl;
    }
    
    return 0;
}
