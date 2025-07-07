#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    string userChoice;

    do {
        double num1, num2;
        char op;

        cout << "\nEnter an operation (+, -, *, /, %, ^, r, !, e, p): ";
        cin >> op;

        switch (op) {
            case '+':
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 + num2 << endl;
                break;

            case '-':
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 - num2 << endl;
                break;

            case '*':
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 * num2 << endl;
                break;

            case '/':
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                if (num2 != 0)
                    cout << "Result: " << num1 / num2 << endl;
                else
                    cout << "Error: Division by zero\n";
                break;

            case '%': {
                int a, b;
                cout << "Enter two integers: ";
                cin >> a >> b;
                if (b != 0)
                    cout << "Result: " << a % b << endl;
                else
                    cout << "Error: Division by zero\n";
                break;
            }

            case '^':
                cout << "Enter base and exponent: ";
                cin >> num1 >> num2;
                cout << "Result: " << pow(num1, num2) << endl;
                break;

            case 'r':
                cout << "Enter number: ";
                cin >> num1;
                if (num1 >= 0)
                    cout << "Square root: " << sqrt(num1) << endl;
                else
                    cout << "Error: Negative input\n";
                break;

            case '!': {
                int n, fact = 1;
                cout << "Enter a non-negative integer: ";
                cin >> n;
                if (n < 0) {
                    cout << "Error: Negative number\n";
                    break;
                }
                for (int i = 1; i <= n; ++i)
                    fact *= i;
                cout << "Factorial: " << fact << endl;
                break;
            }

            case 'e': {
                int even;
                cout << "Enter a number: ";
                cin >> even;
                if (even % 2 == 0)
                    cout << even << " is Even\n";
                else
                    cout << even << " is Odd\n";
                break;
            }

            case 'p': {
                int prime, isPrime = 1;
                cout << "Enter a number: ";
                cin >> prime;
                if (prime <= 1) {
                    cout << "Not a prime number\n";
                    break;
                }
                for (int i = 2; i <= sqrt(prime); ++i) {
                    if (prime % i == 0) {
                        isPrime = 0;
                        break;
                    }
                }
                if (isPrime)
                    cout << "Prime number\n";
                else
                    cout << "Not a prime number\n";
                break;
            }

            default:
                cout << "Invalid operator or option!\n";
        }

        cout << "\nType 'yes' to perform another calculation or 'off' to exit: ";
        cin >> userChoice;

    } while (userChoice == "yes"|| userChoice == "y" || userChoice == "ye");

    cout << "Calculator turned off. Goodbye!\n";

    return 0;
}

