#include <iostream>
#include <cmath>
using namespace std;

// Base class representing an operation
class Operation {
public:
    // Pure virtual function to calculate the result of an operation
    virtual double calculate(double a, double b) const = 0;
    
    // Pure virtual function to get the operator as a string
    virtual string getOperator() const = 0;
};

// Derived class for addition
class Addition : public Operation {
public:
    // Override the calculate function to perform addition
    double calculate(double a, double b) const override {
        return a + b;
    }

    // Override the getOperator function to return the addition operator
    string getOperator() const override {
        return "+";
    }
};

// Derived class for subtraction
class Subtraction : public Operation {
public:
    // Override the calculate function to perform subtraction
    double calculate(double a, double b) const override {
        return a - b;
    }

    // Override the getOperator function to return the subtraction operator
    string getOperator() const override {
        return "-";
    }
};

// Derived class for multiplication
class Multiplication : public Operation {
public:
    // Override the calculate function to perform multiplication
    double calculate(double a, double b) const override {
        return a * b;
    }

    // Override the getOperator function to return the multiplication operator
    string getOperator() const override {
        return "*";
    }
};

// Derived class for division
class Division : public Operation {
public:
    // Override the calculate function to perform division
    double calculate(double a, double b) const override {
        if (b != 0) {
            return a / b;
        } else {
            cerr << "Error: Division by zero!" << endl;
            return NAN; // Not-a-Number for an error
        }
    }

    // Override the getOperator function to return the division operator
    string getOperator() const override {
        return "/";
    }
};

int main() {
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    Operation* op = nullptr;

    switch (operation) {
        case '+':
            op = new Addition();
            break;
        case '-':
            op = new Subtraction();
            break;
        case '*':
            op = new Multiplication();
            break;
        case '/':
            op = new Division();
            break;
        default:
            cerr << "Error: Invalid operation!" <<endl;
            return 1;
    }

    if (op != nullptr) {
        cout << "Result: " << num1 << " " << op->getOperator() << " " << num2 << " = " << op->calculate(num1, num2) <<endl;
        delete op;
    }

    return 0;
}
