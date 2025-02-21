#include <iostream>

int main()
{   
    // Создание переменных 2 типов. (a) и (b) для значений в калькуляторе. meaning - хранит последнее значение.
    // с - знак арифметического калькулятора, либо для символа C/Q
    int a, b, meaning;
    char c;

    // Ввод первого значения
    std::cout << "Input a: ";
    std::cin >> a;

    while (true)
    {   
        // Ввод символа
        std::cout << "Input (+, -, *, /) or C to reset or Q to quit: ";
        std::cin >> c;

        // Проверка на то, что пользователь ввел "C", и пропуск цикла
        if (c == 'C') 
        {
            std::cout << "Resetting result...\n";
            std::cout << "Input a: ";
            std::cin >> a;
            meaning = a; 
            continue; 
        }

        // Проверка ввода "Q"
        if (c == 'Q') 
        {
            std::cout << "Last result: " << meaning << "\n";
            break;
        }

        // Ввод 2 занчения
        std::cout << "Input b: ";
        std::cin >> b;
        // Очистка консоли
        system("cls");

        // Использвания кейсов.
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
                } else 
                    std::cout << "Error: Division by zero!\n";
                    std::cout << "Result: " << meaning << "\n";
                break;
            default:
                std::cout << "Invalid operator. Please enter one of (+, -, *, /, C, Q).\n";
        }
    }
    
    return 0;
}