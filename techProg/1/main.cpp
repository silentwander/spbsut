#include <iostream>

int main()
{
    double a, b, meaning;
    char c;

    std::cout << "Input a: ";
    std::cin >> a;

    do
    {
        std::cout << "Input (+, -, *, /) or C to reset or Q to quit: ";
        std::cin >> c;

        if (c == 'C') 
        {
            std::cout << "Resetting result...\n";
            std::cout << "Input a: ";
            std::cin >> a;
            meaning = a; 
            continue; 
        }

        if (c == 'Q') 
        {
            std::cout << "Last result: " << meaning << "\n";
            break;
        }

        std::cout << "Input b: ";
        std::cin >> b;
        system("cls");

        switch(c)
        {
            case '+':
                meaning = a + b;
                std::cout << "Result: " << meaning << "\n";
                a = meaning;
                break;
            case '-':
                meaning = a - b;
                std::cout << "Result: " << meaning << "\n";
                a = meaning;
                break;
            case '*':
                meaning = a * b;
                std::cout << "Result: " << meaning << "\n";
                a = meaning;
                break;
            case '/':
                if (b != 0) {
                    meaning = a / b;
                    std::cout << "Result: " << meaning << "\n";
                    a = meaning;
                } else {
                    std::cout << "Error: Division by zero!\n";
                }
                break;
            default:
                if (c != 'Q') std::cout << "Invalid operator. Please enter one of (+, -, *, /, C, Q).\n";
        }
    } while (c != 'Q');
    
    return 0;
}
