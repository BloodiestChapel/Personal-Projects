#include <iostream>
#include <istream>
#include <cstring>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    float a = 0.0;
    float b = 0.0;
    float result = 0.0;
    char compType = '0';

    // Get computation type
    cout << "Enter computation type (+, -, /, *): ";
    cin >> compType;

    // Perform calculation based on computation type
    // Also, no exit because I'm assuming the user
    // is not dumb... 
    cout << "\n--------------------------------\n";
    switch(compType)
    {
        // Addition
        case '+':
            cout << "Enter first number to add: ";
            cin >> a;

            cout << "Enter second number to add: ";
            cin >> b;
            cout << endl;

            result = a + b;

            cout << "Sum = " << result << endl;
            break;

        // Subtraction
        case '-':
            cout << "Enter first number to subtract from: ";
            cin >> a;

            cout << "Enter second number to subtract: ";
            cin >> b;
            cout << endl;

            result = a - b;

            cout << "Difference = " << result << endl;
            break;

        // Multiplication
        case '*':
            cout << "Enter multiplier: ";
            cin >> a;

            cout << "Enter multiplicand: ";
            cin >> b;
            cout << endl;

            result = a * b;

            cout << "Product = " << result << endl;
            break;

        // Division
        case '/':
            cout << "Enter dividend: ";
            cin >> a;

            cout << "Enter divisor: ";
            cin >> b;
            cout << endl;

            result = a / b;

            cout << "Quotient = " << result << endl;
            break;

        // Anything else...
        default:
            cout << "Invalid operator." << endl;
            exit(1);
            
    }
    cout << "--------------------------------\n";
    return 0;
}