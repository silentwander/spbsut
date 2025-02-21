#include <iostream>
#include <ctime>

int globalA;
unsigned int globalB, globalOtvetZ1;
long double globalMas[5];
int globalMaxZ2;

// Задание 1
void Input(int &a, unsigned int &b)
{
    std::cout << "Input A and B: ";
    std::cin >> a >> b;
}

int sumV1(int a, unsigned int b)
{   
    return a + b;
}

void sumV2()
{
    globalOtvetZ1 = globalA + globalB;   
}

// Задание 2
long double maxV1(long double (&mas)[5])
{      
    std::cout << "Enter 5 values: ";
    for (int i = 0; i < 5; i++){
        std::cin >> mas[i];
    }

    long double max = mas[0];
    for (int i = 1; i < 5; i++){
        if (max < mas[i]) max = mas[i];
    }

    return max;
}

void maxV2()
{
    std::cout << "Enter 5 values: ";
    for (int i = 0; i < 5; i++){
        std::cin >> globalMas[i];
    }

    globalMaxZ2 = globalMas[0];
    for (int i = 1; i < 5; i++){
        if (globalMaxZ2 < globalMas[i]) globalMaxZ2 = globalMas[i];
    }
}

void Task5(int &button5, char &button)
{
    switch (button5) 
    {
    case 1: button = '1'; break;
    case 2: button = '2'; break;
    case 3: button = '3'; break;
    case 4: button = '4'; break;
    default: break;
    }
}

// Задание 3
void menu(int &a, unsigned int &b, long double (&mas)[5])
{
    char button;
    int button5, otvet;
    bool flag5 = true;
    while (button != 'Q'){   
        if (flag5){
            std::cout << "\n1. Task 1 (V1)\n"<< "2. Task 1 (V2)\n" << "3. Task 2 (V1)\n" << "4. Task 2 (V2)\n" << "5. Random\n" << "Q. Exit\n";
            std::cin >> button;
        } else{
            flag5 = true;
            Task5(button5, button);
        }

        system("cls");
        switch (button)
        {
        case '1':
            Input(a, b);
            otvet = sumV1(a, b); 
            if (otvet >= 32 && otvet <= 126){
                std::cout << "Sum in type char: " << char(otvet) << "\nSizeof: " << sizeof(otvet) <<"\n"; 
            } else std::cout << "Error!\n";
            break;
        case '2':
            Input(globalA, globalB);
            sumV2();
            if (globalOtvetZ1 >= 32 && globalOtvetZ1 <= 126){
                std::cout << "Sum in type char: " << char(globalOtvetZ1) << "\nSizeof: " << sizeof(globalOtvetZ1) << "\n"; 
            } else std::cout << "Error!\n";
            break;
        case '3':
            std::cout << maxV1(mas) << "\n";
            break;
        case '4':
            maxV2();
            std::cout << globalMaxZ2 << "\n";
            break;
        case '5':
            button5 = rand() % 4 + 1;
            flag5 = false;
            break;
        default:
            if (button != 'Q') std::cout << "Error!\n";
        }
    }
    
}

int main() 
{       
    int a;
    unsigned int b;
    long double mas[5];

    menu(a, b, mas);

    return 0;
}