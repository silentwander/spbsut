#include <iostream>
#include <cmath>

class point
{
private:
    int x, y;

public:
    point(int a = 0, int b = 0) : x(a), y(b) {}
    ~point() {}

    void set_x(int a) { x = a; }
    void set_y(int b) { y = b; }
    int get_x() const { return x; }
    int get_y() const { return y; }

    friend int Square(point* points);
};

class document
{
private:
    int num, year;
public:
    document(int a = 0, int b = 0) : num(a), year(b) {}
    ~document() {}

    void set_num(int a) { num = a; }
    void set_year(int b) { year = b; }
    int get_num() const { return num; }
    int get_year() const { return year; }
};

int Square(point* points)
{
    int side1 = std::abs(points[0].y - points[1].y); 
    int side2 = std::abs(points[0].x - points[2].x);
    return side1 * side2;
}

void SideLength(point* points)
{
    int side1 = std::abs(points[0].get_y() - points[1].get_y());
    int side2 = std::abs(points[0].get_x() - points[2].get_x());
    int side3 = std::abs(points[2].get_y() - points[3].get_y());
    int side4 = std::abs(points[1].get_x() - points[3].get_x());

    int diagonal = std::sqrt((side1 * side1) + (side2 * side2));

    std::cout << "Side 1: " << side1 << std::endl;
    std::cout << "Side 2: " << side2 << std::endl;
    std::cout << "Side 3: " << side3 << std::endl;
    std::cout << "Side 4: " << side4 << std::endl;
    std::cout << "Diagonal: " << diagonal << "\n\n";
}

int check(document* docMs)
{
    int count = 0;
    for (int i = 0; i < 6; i ++)
    {
        if (docMs[i].get_year() == 2024) count += docMs[i].get_num();
    }

    return count;
}

int main()
{
    point* m = new point[4];
    m[0].set_x(0); m[0].set_y(0);
    m[1].set_x(0); m[1].set_y(3);
    m[2].set_x(4); m[2].set_y(0);
    m[3].set_x(4); m[3].set_y(3);

    document* docM = new document[6];

    char button;
    int S, docA, docB;

    std::cout << "1. Length and Hypotenuse\n2. Square\n3. Document\nC. Exit\nInput: ";
    std::cin >> button;

    while (button != 'C')
    {
        system("cls");
        switch (button)
        {
        case '1':
            SideLength(m);
            break;
        case '2':
            S = Square(m);
            std::cout << "Square: " << S << "\n\n";
            break;
        case '3':
            system("cls");
            for (int i = 0; i < 6; i++)
            {
                std::cout << "year and num: ";
                std::cin >> docA >> docB;
                docM[i].set_year(docA);
                docM[i].set_num(docB);
            }
            std::cout << "Number of documents issued last year: " << check(docM) << "\n";
            break;
        default:
            if (button != 'C')
                std::cout << "Invalid input. Try again.\n";
            break;
        }
        std::cout << "1. Length and Hypotenuse\n2. Square\n3. Document\nC. Exit\nInput: ";
        std::cin >> button;
    }

    delete[] m;
    delete[] docM;
    return 0;
}