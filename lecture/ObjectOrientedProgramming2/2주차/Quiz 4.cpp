#include <iostream>

class Grade
{
public:
    void Initializer(int, int, int);
    double getAvg();

private:
    int first;
    int second;
    int third;
};

int main()
{
    using namespace std;

    Grade studentA;
    studentA.Initializer(88, 92, 95);
    Grade studentB;
    studentB.Initializer(76, 96, 80);
    Grade studentC;
    studentC.Initializer(98, 78, 97);

    cout << "studentA : " << studentA.getAvg() << endl;
    cout << "studentB : " << studentB.getAvg() << endl;
    cout << "studentC : " << studentC.getAvg() << endl;
}

double Grade::getAvg()
{
    int avg = 0;
    avg = first + second + third;
    avg = avg / 3;
    return avg;
}

void Grade::Initializer(int a, int b, int c)
{
    first = a;
    second = b;
    third = c;
}